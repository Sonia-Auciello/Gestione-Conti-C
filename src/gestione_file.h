#ifndef GESTIONE_FILE_H_
#define GESTIONE_FILE_H_

#include "struct_dati.h"

int scrivi_file(
    const char *nome_file,
    const Conto archivio_conti[],
    unsigned int num_conti
);

unsigned int leggi_file(
    const char *nome_file,
    Conto archivio_conti[],
    unsigned int capacita
);

#endif
