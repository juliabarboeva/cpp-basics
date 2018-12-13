#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    const int kMaxIter = 1000;
    
    double eps, xn, xk, dx;
    cout << "Enter xn: ";
    cin >> xn;
    cout << "Enter xk >= xn: ";
    cin >> xk;
    cout << "Enter dx > 0 : ";
    cin >> dx;
    cout << "Enter EPS > 0: ";
    cin >> eps;
    
    if (dx <= 0) {
        cout << "\nError dx\n";
        return 1;
    }
    else if (xn > xk) {
        cout << "\nError xk\n";
        return 1;
    }
    else if (eps <= 0) {
        cout << "\nError eps\n";
        return 1;
    }
    
    cout << string(72, '-') << endl;
    cout << "|       x       ";
    cout << "|   e^(-x) (mine)    ";
    cout << "|   e^(-x) (cmath)   ";
    cout << "| iterations |\n";
    cout << string(72, '-') << endl;
    
    cout << fixed;
    cout.precision(9);
    
    for (; xn <= xk; xn += dx) {
        
        cout << "|" << setw(13) << xn << setw(3);
        
        int n = 1;
        double func = 0, nth_term = 1;
        while (abs(nth_term) > eps) {
            func += nth_term;
            nth_term = pow((-1), n) * ((pow(xn, n)) / (tgamma(n + 1)));
            n++;
            if (n > kMaxIter) break;
        }
        
        cout << "|" << setw(15);
        if (n <= kMaxIter) {
            cout << func << setw(6) << "|";
        }
        else {
            cout << "   limit exceeded   |";
        }
        cout << setw(15) << exp(-xn) << setw(6) << "|";
        cout << setw(7) << n << setw(7) << "|\n";
    }
    cout << string(72, '-') << endl;
    return 0;
}
