#ifndef FUNZIONI_H_
#define FUNZIONI_H_

#include "struct_dati.h"

void svuota_buffer(void);
void rimuovi_invio(char *stringa);

int genera_valore_casuale(int min, int max);
int valore_corretto(int valore, int valore_minimo, int valore_massimo);
int inserisci_valore(int valore_minimo, int valore_massimo);

void menu(Conto archivio_conti[], unsigned int num_conti);

#endif
