#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "conto.h"

void testing(void)
{
    assert(anno_bisestile(2000) == 1);
    assert(anno_bisestile(2004) == 1);
    assert(anno_bisestile(1900) == 0);
    assert(anno_bisestile(2001) == 0);

    assert(giorni_nel_mese(2, 2020) == 29);
    assert(giorni_nel_mese(2, 2019) == 28);
    assert(giorni_nel_mese(4, 2020) == 30);
    assert(giorni_nel_mese(1, 2020) == 31);
    assert(giorni_nel_mese(13, 2020) == 0);

    Conto movimenti[] = {
        {"Deposito", "AAA111AA", 100, 1, 1, 2020},
        {"Prelievo", "AAA111AA", 30, 2, 1, 2020},
        {"Deposito", "BBB222BB", 50, 1, 1, 2020},
        {"Deposito", "BBB222BB", 10, 2, 1, 2020}
    };

    assert(saldo_conto(movimenti, 4, "AAA111AA") == 70);
    assert(saldo_conto(movimenti, 4, "BBB222BB") == 60);

    char codice[DIM_CODICE + 1];
    long saldo = 0;

    assert(conto_saldo_migliore(movimenti, 4, codice, &saldo) == 1);
    assert(strcmp(codice, "AAA111AA") == 0);
    assert(saldo == 70);

    printf("Testing eseguito con successo!\n");
}
