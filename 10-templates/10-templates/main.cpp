#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

template <class T>
void ReadFile(T** matrix, int num_rows, int num_cols, ifstream& fin);

template <class T>
void PrintMatrix(T** matrix, int num_rows, int num_cols);

template <class T>
int CountColumnsWithoutZeroes(T** matrix, int num_rows, int num_cols);

template <class T>
T ComputeCharacteristic(T* row, int num_cols);

template <class T>
void SortMatrix(T** matrix, int num_rows, int num_cols);

template <class T>
bool Execute(string file_name);

int main() {
    string select;
error:
    cout << "Select the data type (0-integer, 1-double, 2-float): ";
    cin >> select;
    if (select == "0") {
        Execute<int>("int.txt");
    }
    else if (select == "1") {
        Execute<double>("double.txt");
    }
    else if (select == "2") {
        Execute<float>("float.txt");
    }
    else {
        cout << "Error input! (Only 0/1/2)\n";
        goto error;
    }
    return 0;
}

template <class T>
bool Execute(string file_name) {
    string path = "/Users/juliabarboevaicloud.com/Documents/";
    path += "cpp-basics/10-templates/10-templates/";
    ifstream fin(path + file_name);
    if (!fin) {
        cout << "File \"" << file_name << "\" not found.\n";
        return 0;
    }
    
    int num_rows = 4;
    int num_cols = 5;
    
    T** matrix = new T*[num_rows];
    for (int i = 0; i < num_rows; i++)
        matrix[i] = new T[num_cols];
    
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
    
    return 1;
}

template <class T>
void ReadFile(T** matrix, int num_rows, int num_cols, ifstream& fin) {
    for (int i = 0; i < num_rows; i++)
        for (int j = 0; j < num_cols; j++)
            fin >> matrix[i][j];
}

template <class T>
void PrintMatrix(T** matrix, int num_rows, int num_cols) {
    T* characteristics = new T[num_rows];
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

template <class T>
int CountColumnsWithoutZeroes(T** matrix, int num_rows, int num_cols) {
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

template <class T>
T ComputeCharacteristic(T* row, int num_cols) {
    T characteristic = 0;
    for (int j = 0; j < num_cols; j++) {
        int buf = static_cast<int>(row[j]);
        if ((row[j] > 0) && (buf % 2 == 0))
            characteristic += row[j];
    }
    return characteristic;
}

template <class T>
void SortMatrix(T** matrix, int num_rows, int num_cols) {
    T* characteristics = new T[num_rows];
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
