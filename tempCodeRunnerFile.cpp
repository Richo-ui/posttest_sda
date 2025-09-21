#include <iostream>
#include <string>
using namespace std;

struct Penerbangan {
    string kode;
    string tujuan;
    string status;
};

void tampilkanData(Penerbangan arr[], int n) {
    cout << "\nDaftar Jadwal Penerbangan:\n";
    for (int i = 0; i < n; i++) {
        cout << i+1 << ". "
            << arr[i].kode << " - "
            << arr[i].tujuan << " - "
            << arr[i].status << endl;
    }
}

void tambahData(Penerbangan arr[], int &n) {
    cout << "\nTambah Jadwal Baru:\n";
    cout << "Kode   : "; cin >> arr[n].kode;
    cout << "Tujuan : "; cin.ignore();
    getline(cin, arr[n].tujuan);
    cout << "Status : "; getline(cin, arr[n].status);
    n++;
}

void updateData(Penerbangan arr[], int n) {
    int idx;
    cout << "\nUpdate Data, pilih nomor: ";
    cin >> idx;
    if (idx >= 1 && idx <= n) {
        cout << "Tujuan baru : "; cin.ignore();
        getline(cin, arr[idx-1].tujuan);
        cout << "Status baru : "; getline(cin, arr[idx-1].status);
        cout << "Data berhasil diupdate!\n";
    } else {
        cout << "Nomor tidak valid!\n";
    }
}

void hapusData(Penerbangan arr[], int &n) {
    int idx;
    cout << "\nHapus Data, pilih nomor: ";
    cin >> idx;
    if (idx >= 1 && idx <= n) {
        for (int i = idx-1; i < n-1; i++) {
            arr[i] = arr[i+1];
        }
        n--;
        cout << "Data berhasil dihapus!\n";
    } else {
        cout << "Nomor tidak valid!\n";
    }
}

void balikData(Penerbangan *arr, int n) {
    int awal = 0, akhir = n-1;
    while (awal < akhir) {
        swap(arr[awal], arr[akhir]);
        awal++;
        akhir--;
    }
    cout << "\nUrutan data berhasil dibalik!\n";
}

int main() {
    Penerbangan jadwal[100] = {
        {"JT101", "Jakarta - Surabaya", "On Time"},
        {"SJ202", "Jakarta - Makassar", "Delayed"},
        {"GA303", "Denpasar - Jakarta", "Boarding"}
    };
    int n = 3;  // jumlah data awal
    int pilih;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tampilkan Data\n";
        cout << "2. Tambah Data\n";
        cout << "3. Update Data\n";
        cout << "4. Hapus Data\n";
        cout << "5. Balik Urutan Data\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
            case 1: tampilkanData(jadwal, n); break;
            case 2: tambahData(jadwal, n); break;
            case 3: updateData(jadwal, n); break;
            case 4: hapusData(jadwal, n); break;
            case 5: balikData(jadwal, n); break;
            case 0: cout << "Keluar program...\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 0);

    return 0;
}