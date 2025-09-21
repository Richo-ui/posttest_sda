#include <iostream>
using namespace std;

struct Mahasiswa
{
    string nama;
    float ipk;
};

struct Node
{
    Mahasiswa mhs;
    Node* next;
};

void addFirst(Node *&head, string nama, float ipk)
{
    Node *nodeBaru = new Node;
    nodeBaru->mhs.nama = nama;
    nodeBaru->mhs.ipk = ipk;
    nodeBaru->next = head;
    head = nodeBaru;
}

void addLast(Node *&head, string nama, float ipk)
{
    Node *nodeBaru = new Node;
    nodeBaru->mhs.nama = nama;
    nodeBaru->mhs.ipk = ipk;
    nodeBaru->next = nullptr;
    
    if (head == nullptr)
    {
        head = nodeBaru;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = nodeBaru;
    nodeBaru->next = nullptr;
}

void addLastTail(Node *&tail, string nama, float ipk)
{
    Node *nodeBaru = new Node;
    nodeBaru->mhs.nama = nama;
    nodeBaru->mhs.ipk = ipk;

    tail->next = nodeBaru;
    nodeBaru->next = nullptr;
    tail = nodeBaru;
}

void addSpecific(Node *&head, int posisi, string nama, float ipk)
{
    if (posisi < 1) 
    {
        cout << "Tidak ada posisi minus" << endl;
        return;
    }
    
    if (posisi == 1)
    {
        addFirst(head, nama, ipk);
        return;
    }

    Node *temp = head;
    int mulai = 1;
    while (temp != nullptr & mulai < posisi - 1)
    {
        temp = temp->next;
    }

    if(temp == nullptr)
    {
        cout << "Gagal menambahkan data" << endl;
        return;
    } else if (temp->next == nullptr)
    {
        addLast(head, nama, ipk);
    } else {
        Node *nodeBaru = new Node;
        nodeBaru->mhs.nama = nama;
        nodeBaru->mhs.ipk = ipk;
        nodeBaru->next = temp->next;
        temp->next = nodeBaru;
    }
}


void transversal(Node *head)
{
    if (head == nullptr) {
        cout << "Linked listnya kosong" << endl;
        return;
    }

    Node *temp = head;
    while (temp != nullptr) {
        cout << "Nama : " << temp->mhs.nama << endl;
        cout << "IPK  : " << temp->mhs.ipk << endl;
        temp = temp->next;
        cout << endl;
    }
    cout << "Sudah habis" << endl;
}

void deleteFirst(Node *&head)
{
    Node *temp = head;
    head = head->next;
    delete temp;
}

void deleteLast(Node *&head, Node *&tail)
{
    Node *temp = head;
    while (temp->next == tail)
    {
        temp = temp->next;
    }

    

    cout << "Nama yang dihapus : " << tail->mhs.nama << endl;
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    Node *firstNode = new Node;
    firstNode->mhs.nama = "Dimas";
    firstNode->mhs.ipk = 4;
    firstNode->next = nullptr;
    head = firstNode;
    tail = firstNode;

    Node *secondNode = new Node;
    secondNode->mhs.nama = "Nabil";
    secondNode->mhs.ipk = 4;
    secondNode->next = nullptr;
    firstNode->next = secondNode;
    tail = secondNode;

    Node *lastNode = new Node;
    lastNode->mhs.nama = "Trigusni";
    lastNode->mhs.ipk = 4;
    lastNode->next = nullptr;
    secondNode->next = lastNode;
    tail = lastNode;

    transversal(head);

    // cout << "Nambahin data di depan" << endl;
    // addFirst(head, "Fauzan", 4);
    // transversal(head);
    
    // cout << "Nambahin data di akhir" << endl;
    // addLastTail(tail, "Bahlil", 1);
    // transversal(tail);
    
    // cout << "Nambahin data di tengah" << endl;
    // addSpecific(head, 2, "Ucup", 5);
    // transversal(head);

    // cout << "Hapus data di awal" << endl;
    // deleteFirst(head);
    // transversal(head);
    
    // cout << "Hapus data di akhir" << endl;
    // deleteLast(head, tail);
    // transversal(head);

    return 0;
}