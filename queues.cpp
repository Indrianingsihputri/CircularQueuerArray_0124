#include <iostream>
using namespace std;

class Queue {
private:
    static const int max = 5;
    int FRONT, REAR;
    int queus_array[5]; 
public:
    Queus() 
    {
        FRONT = -1;
        REAR = -1;
    }

    void insert() {
        int num;
        cout << "Enter a number: ";
        cin >> num;
        cout << endl;

        //1. cek apakah queue penuh
        if ((FRONT == 0 && REAR == max - 1)||(FRONT == REAR + 1)) {
            cout << "Queue is full!" << endl; //1.a
            return;                           //1.b
        }

        //2. cek apakah antrian kosong
        if (FRONT == -1) {
            FRONT = 0; //2.a
            REAR = 0;  //2.b
        }
    }

};