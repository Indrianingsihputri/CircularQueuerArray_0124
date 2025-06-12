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
};