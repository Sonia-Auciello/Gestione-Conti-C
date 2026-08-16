#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conto.h"
#include "funzioni.h"

int anno_bisestile(int anno)
{
    return (anno % 400 == 0) || ((anno % 4 == 0) && (anno % 100 != 0));
}

int giorni_nel_mese(int mese, int anno)
{
    static const int giorni[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (mese < 1 || mese > 12)
        return 0;

    if (mese == 2 && anno_bisestile(anno))
        return 29;

    return giorni[mese - 1];
}

void genera_dati(Conto archivio_conti[], unsigned int num_conti)
{
    static const char *codici[NUM_CODICI] = {
        "ASD789DF", "WER456RT", "ZXC205RT", "PLM147PL", "TYU123PI",
        "MNB456QW", "DFG147QL", "HJK639NB", "QWE110SA", "YUI556DF"
    };

    static const char *operazioni[NUM_OPERAZIONI] = {
        "Prelievo", "Deposito"
    };

    for (unsigned int i = 0; i < num_conti; ++i)
    {
        int anno = genera_valore_casuale(MIN_ANNO, MAX_ANNO);
        int mese = genera_valore_casuale(MIN_MESE, MAX_MESE);
        int giorno_max = giorni_nel_mese(mese, anno);

        strcpy(
            archivio_conti[i].operazione,
            operazioni[genera_valore_casuale(0, NUM_OPERAZIONI - 1)]
        );

        strcpy(
            archivio_conti[i].codice,
            codici[genera_valore_casuale(0, NUM_CODICI - 1)]
        );

        archivio_conti[i].ammontare =
            genera_valore_casuale(MIN_AMMONTARE, MAX_AMMONTARE);

        archivio_conti[i].anno = anno;
        archivio_conti[i].mese = mese;
        archivio_conti[i].giorno = genera_valore_casuale(1, giorno_max);
    }
}

void stampa_dati(const Conto archivio_conti[], unsigned int num_conti)
{
    for (unsigned int i = 0; i < num_conti; ++i)
    {
        printf(
            "\n[%03u] Codice: %s\n"
            "      Operazione: %s\n"
            "      Data: %02d/%02d/%04d\n"
            "      Ammontare: %d\n",
            i + 1,
            archivio_conti[i].codice,
            archivio_conti[i].operazione,
            archivio_conti[i].giorno,
            archivio_conti[i].mese,
            archivio_conti[i].anno,
            archivio_conti[i].ammontare
        );
    }
}

long saldo_conto(
    const Conto archivio_conti[],
    unsigned int num_conti,
    const char *codice
)
{
    long saldo = 0;

    for (unsigned int i = 0; i < num_conti; ++i)
    {
        if (strcmp(archivio_conti[i].codice, codice) == 0)
        {
            if (strcmp(archivio_conti[i].operazione, "Deposito") == 0)
                saldo += archivio_conti[i].ammontare;
            else if (strcmp(archivio_conti[i].operazione, "Prelievo") == 0)
                saldo -= archivio_conti[i].ammontare;
        }
    }

    return saldo;
}

int conto_saldo_migliore(
    const Conto archivio_conti[],
    unsigned int num_conti,
    char codice_migliore[DIM_CODICE + 1],
    long *saldo_migliore
)
{
    if (num_conti == 0 || codice_migliore == NULL || saldo_migliore == NULL)
        return 0;

    long migliore = LONG_MIN;
    char codice[DIM_CODICE + 1] = {0};

    for (unsigned int i = 0; i < num_conti; ++i)
    {
        int gia_valutato = 0;

        for (unsigned int j = 0; j < i; ++j)
        {
            if (strcmp(archivio_conti[j].codice, archivio_conti[i].codice) == 0)
            {
                gia_valutato = 1;
                break;
            }
        }

        if (!gia_valutato)
        {
            long saldo = saldo_conto(
                archivio_conti,
                num_conti,
                archivio_conti[i].codice
            );

            if (saldo > migliore)
            {
                migliore = saldo;
                strcpy(codice, archivio_conti[i].codice);
            }
        }
    }

    strcpy(codice_migliore, codice);
    *saldo_migliore = migliore;
    return 1;
}
