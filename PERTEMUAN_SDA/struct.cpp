#include <iostream>
using namespace std;

int main()
{
    struct mahasiswa 
    {
        int nim;
        float ipk;
        string nama;
        string alamat;
    };
    mahasiswa mhs1;
    mhs1.nim = 2409106062;
    mhs1.ipk = 3.22;
    mhs1.nama = "Fathir";
    mhs1.alamat = "Tenggarong";
    

    int main();
    {
        mahasiswa tama = {
            67, 4, "Tama", "Samarinda"
        };
        cout << "Nama saya : " << tama.nama << endl;
        cout << "NIM saya : " << tama.nim << endl;
    }


    int main();
    {
        mahasiswa data[4];

        data[0].nama = "Naufal";
        data[1].nama = "Fathir";
        data->nama = "Wahyu";

        cout << data[0].nama << endl;
        cout << data[1].nama << endl;
    }
    return 0;
}