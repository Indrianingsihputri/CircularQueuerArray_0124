/**
* @mainpage Documentation for Circular Queue
*
* @section Introduction
* project ini merupakan project structure data
* menggunakan structured data queues dengan pendekatan circular queue array
* 
* @section operations
* project ini memiliki beberapa operai diantara lain:
* 1. Insert 
* 2. Delete 
* 3. Display
*
* @section cara penggunaan
* berikut beberapa menu yang bisa digunakan:
* 1. en queue
* 2. de queue 
* 3. Display
* 4. Exit
*
* @author profil
* - nama : {Indrianingsih putri}
* - nim : {20240140125}
* - kelas : {C}
*
*
*@brief
*@version 1.0
*@date 2025-06-24
*
*@copyright i.putri.ft24@umy.ac.id
*/

#include <iostream>
using namespace std;
/**
* @class Queues
* @brief Class ini untuk operasi lengkap queues
*
*
*/
class Queues {
private:
    int max = 5; //variable untuk private max untuk menyimpan ukuran maximu antrian
    int FRONT; //variable private front untuk menyimpan posisi depan antrian
    int REAR; //variable private front dan rear untuk menyimpan posisi depan dan belakang antrian
    int queues_array[5]; //variable private queues_array untuk menyimpan elemen antrian
public:
    /**
    * @brief costruct a new queues object
    * set default queues null
    * with front = -1 and rear = -1
    */
    Queues() 
    {
        FRONT = -1;
        REAR = -1;
    }

    /**
    * @brief method untuk memasukkan data dalam antrian
    * data dimasukkan dalam variable queues_array
    */
    void insert() {
        int num; /// variable nul untuk menyimpan nilai
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
        else
        {
            if (REAR == max - 1)
                REAR = 0; //2.c
            else
                REAR = REAR + 1; //2.d
        }
        
        queues_array[REAR] = num;

    }

    /**
    *@brief method untuk menghapus data dalam antrian 
    *data dihapuskan dari dalam variable queues_array
    *
    */
    void remove() 
    {
        // cek apakah antrian kosong
        if (FRONT == -1) 
        {
            cout << "Queue underflow\n" << endl;
            return;                           
        }

         cout << "\nthe element deleted from the queue is: " << queues_array[FRONT] << "\n";

        // cek apakah antrian hanya memiliki satu elemen
        if (FRONT == REAR) {
            FRONT = -1; 
            REAR = -1; 
        }
         else
        {
            //jika elemen yang dihapus berada diposisi terakhir array, kembali ke awal array
            if (FRONT == max - 1) 
                FRONT = 0; 
            else
                FRONT = FRONT + 1;

        }
    }


    /**
    * @brief method untuk menampilkan data dalam antrian
    * data yang ditampilkan yang berada variable queue_array
    *
    */
    void display()
    {
        int FRONT_position = FRONT; //variable fort_position untuk menandakan posisi elemen pertama pada variable front
        int REAR_position = REAR; //variable rear_position untuk menandakan posisi elemen terakhir pada variable rear
    

        // cek apakah antrian kosong
        if (FRONT == -1) 
        {
            cout << "Queue is empty\n" << endl;
            return;
        }

        cout << "\nElements in the queue are...\n";
    
        //jika FRONT_position <= REAR_position, iterasi dari FRONT hingga REAR
        if (FRONT_position <= REAR_position)
        {
            while (FRONT_position <= REAR_position) 
            {
                cout << queues_array[FRONT_position] << " ";
                FRONT_position++;
            }

            cout << endl;
        }
        else
        {
            //jika FRONT_position > REAR_position, iterasi dari FRONT hingga akhir array
            while (FRONT_position <= max - 1) 
            {
                cout << queues_array[FRONT_position] << " ";
                FRONT_position++;
            }

            FRONT_position = 0; //kembali ke awal array

            while (FRONT_position <= REAR_position) 
            {
                cout << queues_array[FRONT_position] << " ";
                FRONT_position++;
            }

            cout << endl;
        }
    }
};

/**
* @brief method utama untuk menjalankan program
*
* @return int
*/
int main()
{
    Queues q; ///< objek untuk menggunakan member yang ada pada class queues
    char ch; ///< variable ch untuk menyimpan pilihan pada menu yang diberikan

    while (true)
    {
        try 
        {
            cout << "Menu" << endl;
            cout << "1. Implemen Insert operation" << endl;
            cout << "2. Implemen delete operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4): ";
            cin >> ch;
            cout << endl;

        switch (ch)
            {
                case '1':
                {
                    q.insert();
                    break;
                }
                case '2':
                {
                    q.remove();
                    break;
                }
                case '3':
                {
                    q.display();
                    break;
                }
                case '4':
                {
                    return 0;
                }
                default:
                {
                    cout << "Invalid option!!" << endl;
                    break;
                }
            }
        }

        catch (exception& e) 
        {
            cout << "Check for the values entered. " << endl;
        }

    }

}