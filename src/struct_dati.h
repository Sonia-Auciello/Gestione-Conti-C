/**
 * @file struct_dati.h
 * Strutture dati del programma.
 */

#ifndef STRUCT_DATI_H_
#define STRUCT_DATI_H_

#include "costanti.h"

typedef struct
{
    char operazione[DIM_OPERAZIONE + 1];
    char codice[DIM_CODICE + 1];
    int ammontare;
    int giorno;
    int mese;
    int anno;
} Conto;

#endif
