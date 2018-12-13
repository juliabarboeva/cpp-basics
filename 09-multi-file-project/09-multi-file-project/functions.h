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
