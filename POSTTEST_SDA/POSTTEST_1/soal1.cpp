#include <iostream>
using namespace std;

void cetakArray(int *arr, int n) {
    if (n == 0) return;
    cout << *arr << " ";
    cetakArray(arr + 1, n - 1);
}

void balikArray(int *arr, int n) {
    if (n <= 1) return;
    swap(*arr, *(arr + n - 1));
    balikArray(arr + 1, n - 2);
}

int main() {
    int arr[7] = {2, 3, 5, 7, 11, 13, 17};

    cout << "Array sebelum dibalik: ";
    cetakArray(arr, 7);
    cout << endl;

    balikArray(arr, 7);

    cout << "Array sesudah dibalik: ";
    cetakArray(arr, 7);
    cout << endl;
}
