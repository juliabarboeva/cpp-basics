#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void ReadFile(int** matrix, int num_rows, int num_cols, ifstream& fin);
void PrintMatrix(int** matrix, int num_rows, int num_cols);
int CountColumnsWithoutZeroes(int** matrix, int num_rows, int num_cols);
int ComputeCharacteristic(int* row, int num_cols);
void SortMatrix(int** matrix, int num_rows, int num_cols);

int main() {
    string path = "/Users/juliabarboevaicloud.com/Documents/";
    path += "cpp-basics/06-arrays-2d/06-arrays-2d/";
    ifstream fin(path + "matrix.txt");
    if (!fin) {
        cout << "File \"matrix.txt\" not found.\n";
        return 1;
    }
    
    int num_rows = 4;
    int num_cols = 5;
    
    int** matrix = new int*[num_rows];
    for (int i = 0; i < num_rows; i++)
        matrix[i] = new int[num_cols];
    
    ReadFile(matrix, num_rows, num_cols, fin);
    fin.close();
    
    cout << "Initial matrix:\n";
    PrintMatrix(matrix, num_rows, num_cols);
    
    cout << "\nNumber of columns without zeroes: ";
    cout << CountColumnsWithoutZeroes(matrix, num_rows, num_cols) << endl;
    cout << endl;
    
    cout << "Sorted matrix:\n";
    SortMatrix(matrix, num_rows, num_cols);
    PrintMatrix(matrix, num_rows, num_cols);
    
    for (int i = 0; i < num_rows; i++) delete[] matrix[i];
    delete[] matrix;
    
    return 0;
}

void ReadFile(int** matrix, int num_rows, int num_cols, ifstream& fin) {
    for (int i = 0; i < num_rows; i++)
        for (int j = 0; j < num_cols; j++)
            fin >> matrix[i][j];
}

void PrintMatrix(int** matrix, int num_rows, int num_cols) {
    int* characteristics = new int[num_rows];
    for (int i = 0; i < num_rows; i++)
        characteristics[i] = ComputeCharacteristic(matrix[i], num_cols);
    
    cout << string(5 * num_cols + 1, '-') << endl;
    for (int i = 0; i < num_rows; i++) {
        cout << "|";
        for (int j = 0; j < num_cols; j++) {
            cout << setw(3) << matrix[i][j] << setw(2) << "|";
        }
        cout << "  |" << setw(3) << characteristics[i] << "|\n";
    }
    cout << string(5 * num_cols + 1, '-') << endl;
    
    delete[] characteristics;
}

int CountColumnsWithoutZeroes(int** matrix, int num_rows, int num_cols) {
    int num_cols_wt_zeros = 0;
    for (int j = 0; j < num_cols; j++) {
        bool no_zeros = true;
        for (int i = 0; i < num_rows; i++) {
            if (matrix[i][j] == 0) {
                no_zeros = false;
                break;
            }
        }
        
        if (no_zeros)
            num_cols_wt_zeros++;
    }
    
    return num_cols_wt_zeros;
}

int ComputeCharacteristic(int* row, int num_cols) {
    int characteristic = 0;
    for (int j = 0; j < num_cols; j++)
        if ((row[j] > 0) && (row[j] % 2 == 0))
            characteristic += row[j];
    
    return characteristic;
}

void SortMatrix(int** matrix, int num_rows, int num_cols) {
    int* characteristics = new int[num_rows];
    for (int i = 0; i < num_rows; i++)
        characteristics[i] = ComputeCharacteristic(matrix[i], num_cols);
    
    for (int i = 0; i < num_rows - 1; i++)
        for (int j = 0; j < num_rows - i - 1; j++)
            if (characteristics[j] > characteristics[j + 1]) {
                swap(matrix[j], matrix[j + 1]);
                swap(characteristics[j], characteristics[j + 1]);
            }
    
    delete[] characteristics;
}
