#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "conto.h"
#include "costanti.h"
#include "funzioni.h"
#include "gestione_file.h"
#include "struct_dati.h"

int main(void)
{
    Conto archivio_conti[NUM_CONTI];

    srand((unsigned int) time(NULL));

    unsigned int letti = leggi_file(
        FILE_DATI,
        archivio_conti,
        NUM_CONTI
    );

    if (letti != NUM_CONTI)
    {
        genera_dati(archivio_conti, NUM_CONTI);

        if (!scrivi_file(FILE_DATI, archivio_conti, NUM_CONTI))
        {
            fprintf(
                stderr,
                "Attenzione: impossibile salvare il file dei dati.\n"
            );
        }
        else
        {
            printf("Archivio iniziale generato correttamente.\n");
        }
    }
    else
    {
        printf("Archivio caricato da %s.\n", FILE_DATI);
    }

    menu(archivio_conti, NUM_CONTI);
    return EXIT_SUCCESS;
}
