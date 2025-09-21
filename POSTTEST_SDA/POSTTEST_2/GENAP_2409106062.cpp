#include <iostream>
#include <string>
using namespace std;


struct Maskapai {
    string kodePenerbangan;
    string tujuan;
    string status;
};


struct Node {
    Maskapai data;
    Node* next;
};


Node* head = nullptr;
Node* tail = nullptr;
int counterKode = 0;


void header() {
    cout << "+------------------------------------------------------------+\n";
    cout << "|              SISTEM JADWAL PENERBANGAN                     |\n";
    cout << "|         Richo Anan Rizky Putra - 2409106062                |\n";
    cout << "+------------------------------------------------------------+\n";
}


string generateKode() {
    string base = "JT-062";
    if (counterKode == 0) {
        counterKode++;
        return base;
    } else {
        return base + "-" + to_string(counterKode++);
    }
}


void tambahJadwal(string tujuan, string status) {
    Node* newNode = new Node;
    newNode->data.kodePenerbangan = generateKode();
    newNode->data.tujuan = tujuan;
    newNode->data.status = status;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    cout << "Jadwal berhasil ditambahkan!\n";
}


void sisipJadwal(string tujuan, string status) {
    int posisi = 3;
    Node* newNode = new Node;
    newNode->data.kodePenerbangan = generateKode();
    newNode->data.tujuan = tujuan;
    newNode->data.status = status;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = tail = newNode;
        cout << "Linked list kosong, jadwal jadi node pertama\n";
        return;
    }

    Node* temp = head;
    int count = 1;
    while (temp != nullptr && count < posisi - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Posisi lebih besar dari jumlah node, jadwal ditambahkan di akhir\n";
        tail->next = newNode;
        tail = newNode;
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }
    cout << "Jadwal berhasil disisipkan di posisi ke-" << posisi << "!\n";
}


void hapusAwal() {
    if (head == nullptr) {
        cout << "Tidak ada jadwal untuk dihapus\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    if (head == nullptr) {
        tail = nullptr;
    }
    cout << "Jadwal paling awal berhasil dihapus\n";
}


void updateStatus(string kode) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.kodePenerbangan == kode) {
            cout << "Masukkan status baru: ";
            cin.ignore();
            getline(cin, temp->data.status);
            cout << "Status berhasil diperbarui\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Kode penerbangan tidak ditemukan\n";
}


void tampilkan() {
    if (head == nullptr) {
        cout << "Tidak ada jadwal penerbangan\n";
        return;
    }
    Node* temp = head;
    cout << "\nDaftar Jadwal Penerbangan:\n";
    cout << "------------------------------------------------------------\n";
    while (temp != nullptr) {
        cout << "Kode   : " << temp->data.kodePenerbangan << endl;
        cout << "Tujuan : " << temp->data.tujuan << endl;
        cout << "Status : " << temp->data.status << endl;
        cout << "------------------------------------------------------------\n";
        temp = temp->next;
    }
}

int main() {
    int pilihan;
    string tujuan, status, kode;

    tambahJadwal("Jakarta", "Tepat Waktu");
    tambahJadwal("Surabaya", "Terlambat");
    tambahJadwal("Medan", "Naik Pesawat");

    do {
        header();
        cout << "| 1. Tambah Jadwal Penerbangan                               |\n";
        cout << "| 2. Sisipkan Jadwal Penerbangan                             |\n";
        cout << "| 3. Hapus Jadwal Paling Awal                                |\n";
        cout << "| 4. Update Status Penerbangan                               |\n";
        cout << "| 5. Tampilkan Semua Jadwal                                  |\n";
        cout << "| 0. Keluar                                                  |\n";
        cout << "+------------------------------------------------------------+\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cin.ignore();
                cout << "Masukkan tujuan: ";
                getline(cin, tujuan);
                cout << "Masukkan status: ";
                getline(cin, status);
                tambahJadwal(tujuan, status);
                break;
            case 2:
                cin.ignore();
                cout << "Masukkan tujuan: ";
                getline(cin, tujuan);
                cout << "Masukkan status: ";
                getline(cin, status);
                sisipJadwal(tujuan, status);
                break;
            case 3:
                hapusAwal();
                break;
            case 4:
                cin.ignore();
                cout << "Masukkan kode penerbangan yang ingin diupdate: ";
                getline(cin, kode);
                updateStatus(kode); 
                break;
            case 5:
                tampilkan();
                break;
            case 0:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid\n";
        }
        cout << endl;
    } while (pilihan != 0);

    return 0;
}