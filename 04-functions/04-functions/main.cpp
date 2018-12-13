#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

void PrintTableHead() {
    cout << string(72, '-') << endl;
    cout << "|       x       ";
    cout << "|   e^(-x) (mine)    ";
    cout << "|   e^(-x) (cmath)   ";
    cout << "| iterations |\n";
    cout << string(72, '-') << endl;
}

double ComputeSeries(double x, double eps, int &n, const int kMaxIter) {
    n = 1;
    double nth_term = 1;
    double func = nth_term;
    while (abs(nth_term) > eps) {
        nth_term = pow((-1), n) * ((pow(x, n)) / (tgamma(n + 1)));
        func += nth_term;
        n++;
        if (n > kMaxIter) break;
    }
    return func;
}

void PrintTableRow(double x, double func, int n, const int kMaxIter) {
    cout << "|" << setw(13) << x << setw(3) << "|" << setw(15);
    if (n <= kMaxIter)
        cout << func << setw(6) << "|";
    else
        cout << "   limit exceeded   |";
    cout << setw(15) << exp(-x) << setw(6) << "|";
    cout << setw(7) << n << setw(7) << "|\n";
}

int main() {
    const int kMaxIter = 1000;
    
    double xn, xk, dx, eps;
    cout << "Enter xn: ";
    cin >> xn;
    cout << "Enter xk >= xn: ";
    cin >> xk;
    cout << "Enter dx > 0: ";
    cin >> dx;
    cout << "Enter eps > 0: ";
    cin >> eps;
    
    if (dx <= 0) {
        cout << "\nError dx.\n";
    }
    else if (eps <= 0) {
        cout << "\nError eps.\n";
    }
    else if (xn > xk) {
        cout << "\nError xk.\n";
    }
    else {
        cout << fixed;
        cout.precision(9);
        
        PrintTableHead();
        for (; xn <= xk; xn += dx) {
            int n;
            double func = ComputeSeries(xn, eps, n, kMaxIter);
            PrintTableRow(xn, func, n, kMaxIter);
        }
        cout << string(72, '-') << endl;
    }
    
    return 0;
}
