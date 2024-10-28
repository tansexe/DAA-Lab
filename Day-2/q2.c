#include <stdio.h>
#include <stdlib.h>

// Recursive function to find the GCD of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Function to read pairs of numbers from a file
int readPairsFromFile(const char *filename, int ***pairs, int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    *count = 0;
    int capacity = 10;
    *pairs = malloc(capacity * sizeof(int *));
    if (*pairs == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return -1;
    }

    int a, b;
    while (fscanf(file, "%d %d", &a, &b) == 2) {
        if (*count >= capacity) {
            capacity *= 2;
            *pairs = realloc(*pairs, capacity * sizeof(int *));
            if (*pairs == NULL) {
                perror("Error reallocating memory");
                fclose(file);
                return -1;
            }
        }
        (*pairs)[*count] = malloc(2 * sizeof(int));
        if ((*pairs)[*count] == NULL) {
            perror("Error allocating memory");
            fclose(file);
            return -1;
        }
        (*pairs)[*count][0] = a;
        (*pairs)[*count][1] = b;
        (*count)++;
    }

    fclose(file);
    return 0;
}

// Function to write results to a file
void writeResultsToFile(const char *filename, int **pairs, int count) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < count; i++) {
        int a = pairs[i][0];
        int b = pairs[i][1];
        int result = gcd(a, b);
        fprintf(file, "GCD of %d and %d is %d\n", a, b, result);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    const char *inputFileName = argv[1];
    const char *outputFileName = argv[2];

    int **pairs;
    int count;
    if (readPairsFromFile(inputFileName, &pairs, &count) != 0) {
        return 1;
    }

    writeResultsToFile(outputFileName, pairs, count);

    // Free allocated memory
    for (int i = 0; i < count; i++) {
        free(pairs[i]);
    }
    free(pairs);

    return 0;
}
