#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a;
    cout << "Write a: ";
    cin >> a;
    
    double z1 = cos(a) + sin(a) + cos(3*a) + sin(3*a);
    double z2 = 2 * sqrt(2) * cos(a) * sin(M_PI/4 + 2*(a));
    
    cout << "z1 = " << z1 << "\nz2 = " << z2 << endl;
    return 0;
}
