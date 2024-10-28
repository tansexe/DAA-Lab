#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Function to print the optimal parenthesization
void printOptimalParenthesis(vector<vector<int>>& S, int i, int j) {
    if (i == j) {
        cout << "A" << i + 1;
    } else {
        cout << "(";
        printOptimalParenthesis(S, i, S[i][j]);
        printOptimalParenthesis(S, S[i][j] + 1, j);
        cout << ")";
    }
}

// Matrix Chain Multiplication function
void matrixChainMultiplication(const vector<int>& dimensions) {
    int n = dimensions.size() - 1;
    vector<vector<int>> M(n, vector<int>(n, 0));
    vector<vector<int>> S(n, vector<int>(n, 0));

    for (int length = 2; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;
            M[i][j] = numeric_limits<int>::max();

            for (int k = i; k < j; k++) {
                int q = M[i][k] + M[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];
                if (q < M[i][j]) {
                    M[i][j] = q;
                    S[i][j] = k;
                }
            }
        }
    }

    // Output M Table
    cout << "M Table:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < i) {
                cout << "0\t";
            } else {
                cout << M[i][j] << "\t";
            }
        }
        cout << "\n";
    }

    // Output S Table
    cout << "S Table:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j <= i) {
                cout << "0\t";
            } else {
                cout << S[i][j] + 1 << "\t";
            }
        }
        cout << "\n";
    }

    // Print optimal parenthesization
    cout << "Optimal parenthesization: ";
    printOptimalParenthesis(S, 0, n - 1);
    cout << endl;

    // Output minimum number of scalar multiplications
    cout << "The optimal ordering of the given matrices requires " << M[0][n - 1] << " scalar multiplications.\n";
}

int main() {
    int numMatrices;
    cout << "Enter number of matrices: ";
    cin >> numMatrices;

    vector<int> dimensions(numMatrices + 1);

    // Input dimensions of matrices
    for (int i = 0; i < numMatrices; i++) {
        cout << "Enter row and col size of A" << i + 1 << ": ";
        int row, col;
        cin >> row >> col;

        if (i == 0) {
            dimensions[i] = row;
        } else if (dimensions[i] != row) {
            cerr << "Error: Incompatible matrix dimensions.\n";
            return 1;
        }

        dimensions[i + 1] = col;
    }

    matrixChainMultiplication(dimensions);

    return 0;
}
