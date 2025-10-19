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

void printRanking(Node* root, int& rank) {
    if (root != nullptr) {
        printRanking(root->left, rank);
        cout << rank << "." << root->nama << " Nilai: " << root->nilai << "\n";
        rank++;
        printRanking(root->right, rank);
    }
}

int main() {
    Node* root = nullptr;
    int pilih;
    int rank = 1;
    
do {
    cout << "1. Tambah data siswa\n";
    cout << "2. Tampilkan ranking dan keluar\n";
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
} while (pilih != 2);
 
cout << "RANKING SISWA\n";
printRanking(root, rank);
return 0;
}