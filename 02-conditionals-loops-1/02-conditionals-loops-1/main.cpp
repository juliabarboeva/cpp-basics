#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    const double kEps = 1e-15;
    
    double xn, xk, dx, a, b, c;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;
    cout << "Enter xn: ";
    cin >> xn;
    cout << "Enter xk >= xn: ";
    cin >> xk;
    cout << "Enter dx > 0: ";
    cin >> dx;
    
    if (dx <= 0) {
        cout << "\nError dx\n";
    }
    else if (xn > xk) {
        cout << "\nError xk\n";
    }
    else {
        cout << string(37, '-') << endl;
        cout << "|" << setw(9) << "x" << setw(9);
        cout << "|" << setw(9) << "F" << setw(10) << "|\n";
        cout << string(37, '-') << endl;
        
        cout << fixed;
        cout.precision(3);
        
        while (xn <= xk) {
            cout << "|" << setw(11) << xn << setw(7) << "|";
            
            double f;
            if (((xn + 5) < 0) and (abs(c) < kEps)) {
                if ((a * xn) >= kEps) {
                    f = 1 / (a * xn) - b;
                }
                else {
                    cout << "  division by 0  |\n";
                    xn += dx;
                    continue;
                }
            }
            else if (((xn + 5) > 0) and (abs(c) >= kEps)) {
                if (abs(xn) >= kEps) {
                    f = (xn - a) / xn;
                }
                else {
                    cout << "  division by 0  |\n";
                    xn += dx;
                    continue;
                }
            }
            else {
                if (abs(c - 4) >= kEps) {
                    f = 10 * xn / (c - 4);
                }
                else {
                    cout << "  division by 0  |\n";
                    xn += dx;
                    continue;
                }
            }
            
            int ac = static_cast<int>(a);
            int bc = static_cast<int>(b);
            int cc = static_cast<int>(c);
            
            if (((ac & bc) | (bc & cc)) != 0)
                cout << setw(11) << f << setw(7);
            else
                cout << setw(9) << static_cast<int>(f) << setw(9);
            cout << "|" << endl;
            
            xn += dx;
        }
        cout << string(37, '-') << endl;
    }
    
    return 0;
}
