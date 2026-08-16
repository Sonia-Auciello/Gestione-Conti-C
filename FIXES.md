# Correzioni apportate

La versione pubblicata in questo repository mantiene l'idea e le funzionalità del progetto originale, ma corregge diversi problemi tecnici.

## Correzioni principali

- corretta la gestione del file binario evitando il classico errore `while (!feof(file))`;
- la lettura ora rispetta la capacità massima dell'array;
- il file viene rigenerato solo quando manca o non contiene il numero atteso di record;
- corretta la generazione delle date: febbraio e gli anni bisestili sono ora gestiti correttamente;
- rimossa la definizione duplicata di `NUM_CODICE`;
- eliminati warning di confronto signed/unsigned;
- resa sicura la rimozione del carattere di invio;
- migliorata la validazione dell'input numerico con `strtol`;
- sostituita la precedente ricerca del semplice movimento con ammontare massimo con il calcolo effettivo del saldo aggregato per codice conto:
  - `Deposito` aumenta il saldo;
  - `Prelievo` diminuisce il saldo;
- ampliati i test automatici con casi su:
  - anni bisestili;
  - giorni dei mesi;
  - calcolo saldo;
  - ricerca del conto con saldo migliore;
- rimosso dal repository il vecchio `file.txt` binario generato a runtime;
- aggiunti Makefile e script Windows per compilazione/esecuzione.

## Verifica

La versione è compilata con:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic
```

senza warning.
