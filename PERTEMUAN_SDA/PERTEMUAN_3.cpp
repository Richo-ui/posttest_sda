#include <iostream>
#include <string>
using namespace std;

int panjangList = 0;

struct mobil 
{
    string merek;
    string nama;
    int topSpeed;
};

struct Node
{
    mobil mbl;
    Node* next;
    Node* prev;
};

void addFirst(Node *&head, Node *&tail)
{
    Node *newNode = new Node;
    cout << "Masukkan merek mobil: ";
    cin >> newNode->mbl.merek;
    getline(cin, newNode->mbl.merek);
    cout << "Masukkan nama mobil: ";
    cin >> newNode->mbl.nama;
    getline(cin, newNode->mbl.nama);
    cout << "Masukkan top speed mobil: ";
    cin >> newNode->mbl.topSpeed;
    
    if (head == NULL && tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    newNode->next = head;
    head = newNode;
    panjangList++;
}

void addLast(Node *&head, Node *&tail)
{
    Node *newNode = new Node;
    cout << "Masukkan merek mobil: ";
    cin >> newNode->mbl.merek;
    cin.ignore();
    getline(cin, newNode->mbl.merek);
    cout << "Masukkan nama mobil: ";
    cin >> newNode->mbl.nama;
    cin.ignore();
    getline(cin, newNode->mbl.nama);
    cout << "Masukkan top speed mobil: ";
    cin >> newNode->mbl.topSpeed;
    
    if (head == nullptr && tail == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    newNode->prev = tail;
    tail = newNode;
    panjangList++;
}

void insertAt(Node *&head, Node *&tail, int posisi)
{
    if (posisi < 1 || posisi > panjangList + 1) {
        cout << "Posisi tidak valid!" << endl;
        return;
    }
    
    if (posisi == 1) {
        addFirst(head, tail);
    } else if (posisi == panjangList + 1) {
        addLast(head, tail);
    } else {
        cout << "\nTambah data di " << posisi << endl;
        Node *newNode = new Node();
        cout << "Merek: "; cin.ignore(); getline(cin, newNode->mbl.merek);
        cout << "Nama: "; cin >> newNode->mbl.nama;
        cout << "Top Speed: "; cin >> newNode->mbl.topSpeed;

        Node *temp = head;
        for (int i = 1; i < posisi - 1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;

        panjangList++;
    }
}

void deleteFirst(Node *&head, Node *&tail)
{
    if (panjangList == 0)
    {
        cout << "Linked List kosong" << endl;
        return;
    }
    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
        panjangList--;
        cout << "Data telah dihapus" << endl;
    }
    else
    {
        Node *del = head;
        head = head->next;
        head->prev = NULL;
        delete del;
        panjangList--;
    }
}

void deleteLast(Node *&head, Node *&tail)
{
    if (panjangList == 0)
    {
        cout << "Linked List kosong" << endl;
        return;
    }
    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
        panjangList--;
        cout << "Data telah dihapus" << endl;
    }
    else
    {
        Node *del = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete del;
        cout << "Data telah dihapus" << endl;
        panjangList--;
    }
}

void deleteSpecific(Node *&head, Node *&tail, int posisi)
{
    if (posisi < 1 || posisi > panjangList) {
        cout << "Posisi tidak valid!" << endl;
        return;
    }
    
    if (posisi == 1) {
        deleteFirst(head, tail);
    } else if (posisi == panjangList) {
        deleteLast(head, tail);
    } else {
        Node *temp = head;
        for (int i = 1; i < posisi - 1; i++) {
            temp = temp->next;
        }

        Node *del = temp->next;
        temp->next = del->next;
        del->next->prev = temp;
        delete del;

        panjangList--;
    }
}

void showList(Node *head)
{
    if (panjangList == 0)
    {
        cout << "Linked List kosong" << endl;
        return;
    }
    cout << "\nLinked List: " << endl;
    int i = 1;
    while(head != nullptr)
    {
        cout << i++ << "Merek : " << head->mbl.merek << endl;
        cout << "Nama  : " << head->mbl.nama << endl;
        cout << "Top Speed : " << head->mbl.topSpeed << " km/h" << endl;
        head = head->next;
    }
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;

    int pilih;
    cout << "Menu Double Linked List" << endl;
    cout << "1. Tambah data di awal" << endl;
    cout << "2. Tambah data di akhir" << endl;
    cout << "3. Tambah data di posisi tertentu" << endl;
    cout << "4. Hapus data di awal" << endl;
    cout << "5. Hapus data di akhir" << endl;
    cout << "6. Hapus data di posisi tertentu" << endl;
    cout << "7. Tampilkan data" << endl;
    cout << "0. Keluar" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilih;
    
    if (pilih == 0) {
        cout << "Keluar dari program." << endl;
        return 0;
    }
    else if (pilih == 1) {
        addFirst(head, tail);
        showList(head);
    }
    else if (pilih == 2) {
        addLast(head, tail);
        showList(head);
    }
    else if (pilih == 3) {
        int posisi;
        cout << "Masukkan posisi: ";
        cin >> posisi;
        insertAt(head, tail, posisi);
        showList(head);
    }
    else if (pilih == 4) {
        deleteFirst(head, tail);
        showList(head);
    }
    else if (pilih == 5) {
        deleteLast(head, tail);
        showList(head);
    }
    else if (pilih == 6) {
        int posisi;
        cout << "Masukkan posisi: ";
        cin >> posisi;
        deleteSpecific(head, tail, posisi);
        showList(head);
    }
    else if (pilih == 7) {
        showList(head);
    }
    else {
        cout << "Pilihan tidak valid." << endl;
    }
}