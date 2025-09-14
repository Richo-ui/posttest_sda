#include <iostream>
using namespace std;

void tukar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 5, b = 9;
    cout << "Sebelum ditukar: a=" << a << " b=" << b << endl;
    tukar(a,b);
    cout << "Sesudah ditukar: a=" << a << " b=" << b << endl;
}