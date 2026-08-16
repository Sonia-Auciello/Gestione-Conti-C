# Gestione Conti in C 💳

### Progetto universitario - Esame di **Laboratorio di Informatica**

**Sonia Auciello**

**Esame:** Laboratorio di Informatica

---

## 📌 Descrizione

Applicazione console sviluppata in **C** per la generazione e la gestione di un archivio di movimenti bancari.

Ogni movimento contiene:

- codice del conto;
- tipo di operazione (`Deposito` o `Prelievo`);
- ammontare;
- data dell'operazione.

I dati vengono generati casualmente, salvati in un file binario e ricaricati nelle esecuzioni successive.

---

## ✨ Funzionalità

Il programma consente di:

- generare 100 movimenti bancari di esempio;
- salvare e leggere i dati da file binario;
- visualizzare tutti i movimenti;
- calcolare il saldo aggregato di ogni codice conto;
- individuare il conto con il saldo più alto;
- rigenerare l'archivio;
- eseguire test automatici tramite `assert`.

Il saldo viene calcolato considerando:

```text
Deposito  -> + ammontare
Prelievo  -> - ammontare
```

---

## 🛠️ Tecnologia

![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)
![GCC](https://img.shields.io/badge/GCC-Compiler-A42E2B?style=flat&logo=gnu&logoColor=white)

Il progetto utilizza esclusivamente la libreria standard del C.

---

## 📂 Struttura

```text
Gestione-Conti-C/
├── src/
│   ├── main.c
│   ├── conto.c
│   ├── conto.h
│   ├── funzioni.c
│   ├── funzioni.h
│   ├── gestione_file.c
│   ├── gestione_file.h
│   ├── testing.c
│   ├── testing.h
│   ├── costanti.h
│   └── struct_dati.h
├── Makefile
├── compile.bat
├── run.bat
├── FIXES.md
├── README.md
├── .gitignore
└── .gitattributes
```

---

## 🚀 Compilazione

### Windows con MinGW / GCC

È possibile eseguire:

```text
compile.bat
```

oppure:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic src\main.c src\conto.c src\funzioni.c src\gestione_file.c src\testing.c -o gestione_conti.exe
```

Avvio:

```text
run.bat
```

### Linux / macOS

```bash
make
./gestione_conti
```

---

## 🧪 Testing

Dal menu scegliere:

```text
3) Esegui i test
```

I test verificano:

- correttezza degli anni bisestili;
- numero di giorni dei mesi;
- gestione di febbraio negli anni bisestili;
- calcolo del saldo di un conto;
- individuazione del conto con saldo migliore.

---

## 💾 Persistenza

Alla prima esecuzione viene creato automaticamente:

```text
dati_conti.bin
```

Il file è escluso da Git tramite `.gitignore`, perché contiene dati generati automaticamente.

---

## 🔧 Revisione del codice

Il codice originale è stato revisionato per correggere problemi di lettura/scrittura da file, date non valide, gestione dell'input e calcolo del saldo.

Tutte le modifiche sono documentate in:

➡️ [`FIXES.md`](FIXES.md)

---

## 🎓 Contesto accademico

**Esame:** Laboratorio di Informatica  
**Linguaggio:** C  
**Studentessa:** Sonia Auciello

---

## ℹ️ Note

Questo repository è pubblicato come progetto accademico e portfolio tecnico.
