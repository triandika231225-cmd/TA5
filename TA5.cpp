#include <iostream>
using namespace std;

struct Node {
    string nama;
    int nilai;
    Node* left;
    Node* right;
};

Node* createNode(string nama, int nilai) {
    Node* newNode = new Node();
    newNode->nama = nama;
    newNode->nilai = nilai;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, string nama, int nilai) {
    if (root == nullptr) {
        return createNode(nama, nilai);
    }
    if (nilai > root->nilai) {
        root->right = insert(root->right, nama, nilai);
    } else {
        root->left = insert(root->left, nama, nilai);
    }
    return root;
}

void printRanking(Node* root) {
    if (root != nullptr) {
        printRanking(root->left);
        cout << root->nama << " Nilai: " << root->nilai << "\n";
        printRanking(root->right);
    }
}

void search(Node* root, int nilai) {
    if (root == nullptr) {
        cout << "Nilai " << nilai << " tidak ditemukan.\n";
        return;
    }
    if (root->nilai == nilai) {
        cout << "Nama: " << root->nama << ", Nilai: " << root->nilai << "\n";
        return;
    }
    if (nilai < root->nilai) {
        search(root->left, nilai);
    } else {
        search(root->right, nilai);
    }
} 

int main() {
    Node* root = nullptr;
    int pilih;
    
do {
    cout << "1. Tambah data siswa\n";
    cout << "2. Cari data siswa\n";
    cout << "3. Tampilkan ranking\n";
    cout << "4. Keluar\n";
    cout << "Pilih: ";
    cin >> pilih;
        
    if (pilih == 1) {
        string nama;
        int nilai;

        cout << "Nama siswa: ";
        cin.ignore();
        getline(cin, nama);
        cout << "Nilai: ";
        cin >> nilai;

        root = insert(root, nama, nilai);
    }
    if (pilih == 2) {
        int nilai;
        cout << "Masukkan nilai siswa: ";
        cin >> nilai;
        search(root,nilai);

    }
    if (pilih == 3) {
        cout << "RANKING SISWA\n";
        printRanking(root);
    }
} while (pilih != 4);
 
return 0;
}
