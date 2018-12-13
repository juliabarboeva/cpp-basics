#include <iostream>
#include <cmath>

using namespace std;

struct AbsMinMaxIndices {
    int min;
    int max;
};

void PrintArray(double* arr, const int kArraySize);
double SumPosElem(double* arr, const int kArraySize);
AbsMinMaxIndices FindAbsMinMaxIndices(double* arr, const int kArraySize);
double ProductBetweenMinMax(double* arr, int begin, int end);
void SortArray(double* arr, const int kArraySize);

int main() {
    const int kArraySize = 10;
    double arr[kArraySize] = { 5, 1, -2, 0, -4, .5, 6, -.7, 8, .4 };
    
    cout << "Initial array:\n";
    PrintArray(arr, kArraySize);
    cout << endl;
    
    cout << "\nSum of positive elements = ";
    cout << SumPosElem(arr, kArraySize) << endl;
    
    AbsMinMaxIndices ammi = FindAbsMinMaxIndices(arr, kArraySize);
    int min_index = ammi.min;
    int max_index = ammi.max;
    if (abs(min_index - max_index) > 1) {
        double product;
        if (min_index < max_index)
            product = ProductBetweenMinMax(arr, min_index, max_index);
        else
            product = ProductBetweenMinMax(arr, max_index, min_index);
        cout << "\nProduct of elements between abs min and abs max = ";
        cout << product << endl;
    }
    else
        cout << "\nNo elements between abs min and abs max.\n";
    
    SortArray(arr, kArraySize);
    cout << "\nSorted array:\n";
    PrintArray(arr, kArraySize);
    cout << endl << endl;
    
    return 0;
}

void PrintArray(double* arr, const int kArraySize) {
    cout << "[";
    for (int i = 0; i < kArraySize; i++)
        cout << arr[i] << ((i < kArraySize-1) ? (", ") : ("]"));
}

double SumPosElem(double* arr, const int kArraySize) {
    double sum = 0;
    for (int i = 0; i < kArraySize; i++)
        if (arr[i] > 0)
            sum += arr[i];
    return sum;
}

AbsMinMaxIndices FindAbsMinMaxIndices(double* arr, const int kArraySize) {
    int min = 0, max = 0;
    for (int i = 1; i < kArraySize; i++) {
        if (abs(arr[i]) < abs(arr[min])) min = i;
        if (abs(arr[i]) > abs(arr[max])) max = i;
    }
    return AbsMinMaxIndices { min, max };
}

double ProductBetweenMinMax(double* arr, int begin, int end) {
    double product = 1;
    for (int i = begin + 1; i < end; i++)
        product *= arr[i];
    return product;
}

void SortArray(double* arr, const int kArraySize) {
    for (int i = 0; i < kArraySize - 1; i++)
        for (int j = 0; j < kArraySize - i - 1; j++)
            if (arr[j] < arr[j+1])
                swap(arr[j], arr[j+1]);
}
