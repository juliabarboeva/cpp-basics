#include "functions.h"

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
