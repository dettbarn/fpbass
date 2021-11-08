#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wavgen.h"

using namespace std;


unsigned int swap(unsigned int i, unsigned int j, unsigned int n, unsigned int b) {
    unsigned int r;

    unsigned int x = ((b >> i) ^ (b >> j)) & ((1U << n) - 1);
    r = b ^ ((x << i) | (x << j));

    return r;
}


int endianswap(unsigned int number) {
    unsigned int result = swap(1, 9, 8, number);
    result = swap(17, 25, 8, result);
    return result;
}


int main() {
    char prefix[] = "RIFF";
    char infix[] = "WAVEfmt\x20\x10\x00\x00\x00\x01\x00\x02\x00\x22\x56\x00\x00\x88\x58\x01\x00\x04\x00\x64\x61\x74\x61\x00\x08\x00\x00";

    char* filename = "output.wav";
    unsigned int fileSize = 2092;
    unsigned int chunkSize = fileSize - 8;
    char data[] = "111111111111111111111111111";

    char chunkSizeFormatted[4];
    int chunkSizeSwapped = endianswap(chunkSize);
    memcpy(chunkSizeFormatted, (char*) &chunkSizeSwapped, sizeof(chunkSizeSwapped));

    FILE *file;
    if (!(file = fopen(filename, "wb"))) return 1;

    fprintf(file, "%s", prefix);
    fwrite(chunkSizeFormatted, sizeof(chunkSizeFormatted), 1, file);
    fwrite(infix, sizeof(infix) - 1, 1, file);
    fwrite(data, sizeof(data), 1, file);

    fclose(file);

    return 0;
}
