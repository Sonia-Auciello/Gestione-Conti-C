#ifndef CONTO_H_
#define CONTO_H_

#include "struct_dati.h"

void genera_dati(Conto archivio_conti[], unsigned int num_conti);
void stampa_dati(const Conto archivio_conti[], unsigned int num_conti);

int anno_bisestile(int anno);
int giorni_nel_mese(int mese, int anno);

long saldo_conto(const Conto archivio_conti[], unsigned int num_conti, const char *codice);
int conto_saldo_migliore(
    const Conto archivio_conti[],
    unsigned int num_conti,
    char codice_migliore[DIM_CODICE + 1],
    long *saldo_migliore
);

#endif
