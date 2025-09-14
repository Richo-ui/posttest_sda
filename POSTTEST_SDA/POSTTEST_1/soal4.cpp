#include <iostream>
using namespace std;

void tukar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 9;
    cout << "Sebelum ditukar: x=" << x << " y=" << y << endl;
    tukar(x,y);
    cout << "Sesudah ditukar: x=" << x << " y=" << y << endl;
}