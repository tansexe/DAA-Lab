#include <stdio.h>
#include <stdlib.h>

// Recursive function to convert decimal to binary and write to the output file
void decimalToBinary(int n, FILE *outputFile)
{
    if (n == 0) {
        fprintf(outputFile, "0");
        return;
    }
    if (n > 1) {
        decimalToBinary(n / 2, outputFile);
    }
    fprintf(outputFile, "%d", n % 2);
}

// Function to process the file and convert numbers to binary
void processFile(const char *inputFileName, const char *outputFileName, int n)
{
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

    if (inputFile == NULL) {
        perror("Error opening input file");
        return;
    }
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return;
    }

    int number;
    for (int i = 0; i < n; i++) {
        if (fscanf(inputFile, "%d", &number) != 1) {
            fprintf(stderr, "Error reading number from file or fewer numbers than expected\n");
            break;
        }
        fprintf(outputFile, "The binary equivalent of %d is ", number);
        decimalToBinary(number, outputFile);
        fprintf(outputFile, "\n"); // Separate binary numbers by new lines
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main(int argc, char *argv[])
{
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <n> <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "The number of decimal values must be positive.\n");
        return EXIT_FAILURE;
    }

    const char *inputFileName = argv[2];
    const char *outputFileName = argv[3];

    processFile(inputFileName, outputFileName, n);

    printf("Conversion completed. Check the output file.\n");

    return EXIT_SUCCESS;
}
