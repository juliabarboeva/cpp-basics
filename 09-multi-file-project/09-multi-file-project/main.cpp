#include "functions.h"

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
