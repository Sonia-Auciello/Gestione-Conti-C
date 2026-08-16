#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conto.h"
#include "costanti.h"
#include "funzioni.h"
#include "gestione_file.h"
#include "testing.h"

void svuota_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void rimuovi_invio(char *stringa)
{
    if (stringa == NULL)
        return;

    stringa[strcspn(stringa, "\r\n")] = '\0';
}

int genera_valore_casuale(int min, int max)
{
    if (min > max)
    {
        int temp = min;
        min = max;
        max = temp;
    }

    return min + rand() % (max - min + 1);
}

int valore_corretto(int valore, int valore_minimo, int valore_massimo)
{
    return valore >= valore_minimo && valore <= valore_massimo;
}

int inserisci_valore(int valore_minimo, int valore_massimo)
{
    char buffer[DIM_INPUT_STRINGA];

    for (;;)
    {
        char *fine = NULL;
        long valore;

        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
            return valore_massimo;

        if (strchr(buffer, '\n') == NULL)
            svuota_buffer();

        rimuovi_invio(buffer);

        errno = 0;
        valore = strtol(buffer, &fine, 10);

        if (
            errno == 0 &&
            fine != buffer &&
            *fine == '\0' &&
            valore >= valore_minimo &&
            valore <= valore_massimo
        )
        {
            return (int) valore;
        }

        printf(
            "Valore non valido. Inserire un numero tra %d e %d: ",
            valore_minimo,
            valore_massimo
        );
    }
}

void menu(Conto archivio_conti[], unsigned int num_conti)
{
    int scelta;

    do
    {
        printf(
            "\n=== Gestione movimenti bancari ===\n"
            "1) Visualizza tutti i movimenti\n"
            "2) Visualizza il conto con saldo migliore\n"
            "3) Esegui i test\n"
            "4) Rigenera i dati\n"
            "5) Termina programma\n"
            "Scelta desiderata: "
        );

        scelta = inserisci_valore(1, 5);

        switch (scelta)
        {
            case 1:
                stampa_dati(archivio_conti, num_conti);
                break;

            case 2:
            {
                char codice[DIM_CODICE + 1];
                long saldo;

                if (
                    conto_saldo_migliore(
                        archivio_conti,
                        num_conti,
                        codice,
                        &saldo
                    )
                )
                {
                    printf(
                        "\nConto con saldo migliore: %s\n"
                        "Saldo calcolato: %ld\n",
                        codice,
                        saldo
                    );
                }
                else
                {
                    printf("Archivio vuoto.\n");
                }
                break;
            }

            case 3:
                testing();
                break;

            case 4:
                genera_dati(archivio_conti, num_conti);
                if (scrivi_file(FILE_DATI, archivio_conti, num_conti))
                    printf("Nuovi dati generati e salvati correttamente.\n");
                else
                    printf("Dati generati, ma salvataggio su file fallito.\n");
                break;

            case 5:
                printf("Programma terminato.\n");
                break;
        }
    }
    while (scelta != 5);
}
