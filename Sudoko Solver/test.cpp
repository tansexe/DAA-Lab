#include <iostream>
#include <string>
using namespace std;

void print(int grid[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void getvalues(int arr[9][9])
{
    cout << "Do you want to initialize values? Type 'y' or 'n': ";
    char ans;
    cin >> ans;
    cin.ignore();
    if (ans == 'y')
    {
        cout << "Enter values for each position (press Enter to leave a cell empty):" << endl;
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                cout << "Enter value for row " << i << " and column " << j << ": ";
                string input;
                getline(cin, input);

                if (input.empty())
                {
                    arr[i - 1][j - 1] = 0;
                }
                else
                {
                    arr[i - 1][j - 1] = stoi(input);
                }
            }
        }
    }
}

bool checking(int arr[9][9], int num, int row, int col)
{
    for (int i = 0; i < 9; i++)
    {
        if (arr[row][i] == num || arr[i][col] == num)
        {
            return false;
        }
    }

    int startRow = 3 * (row / 3), startCol = 3 * (col / 3);
    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            if (arr[i][j] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool filling(int arr[9][9], int row, int col)
{
    if (row == 8 && col == 9)
    {
        return true;
    }
    if (col == 9)
    {
        row++;
        col = 0;
    }
    if (arr[row][col] != 0)
    {
        return filling(arr, row, col + 1);
    }

    for (int num = 1; num <= 9; num++)
    {
        if (checking(arr, num, row, col))
        {
            arr[row][col] = num;
            if (filling(arr, row, col + 1))
            {
                return true;
            }
            arr[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    int grid[9][9] = {0};
    getvalues(grid);
    if (filling(grid, 0, 0))
    {
        cout << "Solved successfully!" << endl;
        print(grid);
    }
    else
    {
        cout << "No possible solution for this puzzle." << endl;
    }
    return 0;
}