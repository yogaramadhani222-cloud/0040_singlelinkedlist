#include <iostream> 
#include <string>
using namespace std;

class Node{
public:
    int noMhs;
    Node *next;
};

class LinkedList{
    Node *START;

public:
    LinkedList(){
        START = NULL;
    }

    void addNode(){ 
        int nim;
        cout << "\n masukkan nomor mahasiswa: ";
        cin >> nim;

        Node *nodeBaru = new Node();
        nodeBaru->noMhs = nim;

        if (START == NULL || nim <= START->noMhs)
        {
            if (START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n" << endl;
                return;
            }

            nodeBaru->next = START;
            START = nodeBaru;
            return;
        }
    }
};