#include <iostream>
using namespace std;

// void changeNumber (int *ptr)
// {
//     cout << "Masukkan nilai :";
//     cin >> *ptr;
//     cout << endl;
// }

// void changeNumber2 (int &ptr)
// {
//     cout << "Masukkan nilai :";
//     cin >> ptr;
//     cout << endl;
// }




int main()
{
    // int number = 10;
    // int *angka = &number;
    // cout << "ini angka : " << angka << endl;
    // cout << "ini pointer angka : " << *angka << endl;
    // cout << "ini prima : " << number << endl;
    // cout << "ini alamat number : " << &number << endl;
    void balikprima(int *prima, int n) {
        if (n <= 1) return;
        swap(*prima, *(prima + n - 1));
        balikprima(prima + 1, n - 2);
    }
    
    int prima[7] = {2, 3, 5, 7, 11, 13, 17};
    cout << "sebelum  dibalik : " << *prima << " " << *(prima+1) << " " << *(prima+2) << " " << *(prima+3) << " " << *(prima+4) << " " << *(prima+5) << " " << *(prima+6) << endl;
    cout << " " << endl;
    cout << "sesudah dibalik : " << balikprima << endl;
    cout << " " << endl;

    // changeNumber(&number);
    

    // int number = 10;
    // int *ptr = &number;
    // int **ptr2 = &ptr;
    // int ***ptr3 = &ptr2;

    // cout << ***ptr3 << endl;

    // cout << "Alamat number: " << &number << endl;
    // cout << "Nilai ptr : " << ptr << endl;
    // cout << "Alamat ptr : " << &ptr <<endl;

    // cout << "Sebelum : " << number << endl;
    // *ptr = 30;
    // cout << "Sesudah : " << number << endl;

    return 0;
}