#include <iostream>
using namespace std;

const int MAX = 5;
int queue[MAX];
int front = -1, rear = -1;

// Cek kosong
bool isEmpty() {
    return front == -1;
}

// Cek penuh
bool isFull() {
    return (rear + 1) % MAX == front;
}

// Enqueue
void enqueue(int data) {
    if (isFull()) {
        cout << "Queue penuh.\n";
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = data;
    cout << "Data " << data << " berhasil dimasukkan.\n";
}

// Dequeue
void dequeue() {
    if (isEmpty()) {
        cout << "Queue kosong.\n";
        return;
    }

    cout << "Data " << queue[front] << " dikeluarkan.\n";

    if (front == rear) {
        front = rear = -1; // hanya 1 elemen
    } else {
        front = (front + 1) % MAX;
    }
}

// Tampilkan isi queue
void display() {
    if (isEmpty()) {
        cout << "Queue kosong.\n";
        return;
    }

    cout << "Isi Queue: ";
    int i = front;
    while (true) {
        cout << queue[i] << " ";
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main() {
    int pilihan, data;

    do {
        cout << "\n=== Menu Circular Queue ===\n";
        cout << "1. Enqueue (Tambah Data)\n";
        cout << "2. Dequeue (Hapus Data)\n";
        cout << "3. Tampilkan Queue\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan data: ";
                cin >> data;
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 4);

    return 0;
}
