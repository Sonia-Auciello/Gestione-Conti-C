#include <stdio.h>

#include "gestione_file.h"

int scrivi_file(
    const char *nome_file,
    const Conto archivio_conti[],
    unsigned int num_conti
)
{
    FILE *file = fopen(nome_file, "wb");

    if (file == NULL)
        return 0;

    size_t scritti = fwrite(
        archivio_conti,
        sizeof(Conto),
        num_conti,
        file
    );

    int errore_chiusura = fclose(file);
    return scritti == num_conti && errore_chiusura == 0;
}

unsigned int leggi_file(
    const char *nome_file,
    Conto archivio_conti[],
    unsigned int capacita
)
{
    FILE *file = fopen(nome_file, "rb");

    if (file == NULL)
        return 0;

    size_t letti = fread(
        archivio_conti,
        sizeof(Conto),
        capacita,
        file
    );

    fclose(file);
    return (unsigned int) letti;
}
