#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    float ipk;
};

int main() {
    Mahasiswa mhs1 = {"Junko", 101, 3.6};
    Mahasiswa mhs2 = {"Mukuro", 102, 3.2};
    Mahasiswa mhs3 = {"Monokuma", 103, 4.0};
    Mahasiswa mhs4 = {"Monomi", 104, 3.9};

    cout << mhs2.nama << " " << mhs2.nim << " " << mhs2.ipk << endl;
    cout << mhs1.nama << " " << mhs1.nim << " " << mhs1.ipk << endl;
    cout << mhs4.nama << " " << mhs4.nim << " " << mhs4.ipk << endl;
    cout << mhs3.nama << " " << mhs3.nim << " " << mhs3.ipk << endl;
}