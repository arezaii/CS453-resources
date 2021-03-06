
/* C-examples/files/generate_binary.c */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "record.h"

/**
 * Writes the record to the given file handle using fwrite.
 * (aka. dumps it in binary format)
 */
static void write_record(struct record *r, FILE *fout)
{
    fwrite(r, sizeof(struct record), 1, fout);
}

int main(int argc, char **argv)
{
    const char *filename = "data.bin";
    unsigned int seed;
    unsigned int n;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <n> [<seed>]\n", argv[0]);
        exit(1);
    }

    n = atoi(argv[1]);
    if (argc == 3) {
        seed = atoi(argv[1]);
        srandom(seed); /* this should ONLY be done if seed is entered */
    }

    generate_record_file(n, filename, write_record);

    return 0;
}
