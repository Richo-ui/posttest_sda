#include <iostream>
using namespace std;

int main() {
    int matriks[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Matriks 3x3 : " << endl;
    cout << matriks[0][0] << " " << matriks[0][1] << " " << matriks[0][2] << endl;
    cout << matriks[1][0] << " " << matriks[1][1] << " " << matriks[1][2] << endl;
    cout << matriks[2][0] << " " << matriks[2][1] << " " << matriks[2][2] << endl;

    int jumlah = matriks[0][0] + matriks[0][1] + matriks[0][2] + matriks[2][0] + matriks[2][1] + matriks[2][2];

    cout << "Jumlah elemen pada baris genap: " << jumlah << endl;

    return 0;
}