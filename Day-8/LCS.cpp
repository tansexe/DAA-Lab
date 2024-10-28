#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to find the LCS of two strings
string findLCS(const string& X, const string& Y) {
    int m = X.size();
    int n = Y.size();
    
    // Create a 2D table to store lengths of LCS
    vector<vector<int>> L(m + 1, vector<int>(n + 1, 0));

    // Fill the LCS table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    // Length of LCS
    int lengthOfLCS = L[m][n];
    
    // Reconstruct the LCS from the table
    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs = X[i - 1] + lcs;
            i--;
            j--;
        } else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Output the LCS and its length
    cout << "LCS: " << lcs << endl;
    cout << "LCS Length: " << lengthOfLCS << endl;
    
    return lcs;
}

int main() {
    string X, Y;
    cout << "Enter the first string into an array: ";
    cin >> X;
    cout << "Enter the second string into an array: ";
    cin >> Y;

    findLCS(X, Y);

    return 0;
}
