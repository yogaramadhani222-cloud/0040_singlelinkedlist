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

        Node *previous, *current;
        current = START;

        while (current != NULL && nim > current->noMhs)
        {
            if (nim == current->noMhs)
            {
                cout << "\nDuplikasi noMhs tidak diijinkan\n" << endl;
                return;
            }
            previous = current;
            current = current->next;
        }
    }

    bool listEmpty(){
        return (START == NULL);
    }

    bool search(int nim, Node *&previous, Node *&current)
    {
        previous = START;
        current = START;

        while (current != NULL && nim != current->noMhs)
        {
            previous = current;
            current = current->next;
        }

        return (current != NULL);
    }

    bool delNode(int nim)
    {
        Node *current, *previous;
        if (!search(nim, previous, current))
            return false;

        if (current == START)
        {
            START = START->next;
        }
        else
        {
            previous->next = current->next;
        }

        delete current;
        return true;
    }

    void traverse()
    {
        if (listEmpty())
        {
            cout << "\nList Kosong\n" << endl;
        }
        else
        {
            cout << "\nData dalam list: \n" << endl;
            Node *currentNode = START;

            while (currentNode != NULL)
            {
                cout << currentNode->noMhs << " ";
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    LinkedList mhs;
    int nim;
    char ch;

    do
    {
        cout << "\n menu" << endl;
        cout << "1.menambah Data kedalam list" << endl;
        cout << "2.menghapus Data dari dalam list" << endl;
        cout << "3.menampilkan Data dalam list" << endl;
        cout << "4.mencari data dalam list" << endl;
        cout << "5.keluar" << endl;

        cout << "\n masukkan pilihan 1-5:";
        cin >> ch;
        
        switch (ch)
        {
        case '1':
            mhs.addNode();
            break;

        case '2':
            if (mhs.listEmpty())
            {
                cout << "\nList Kosong\n" << endl;
                break;
            }

            cout << "\n masukkan nomor mahasiswa yang akan dihapus: ";
            cin >> nim;

            if (mhs.delNode(nim) == false)
            {
                cout << "\nData tidak ditemukan\n" << endl;
            }
            else
            {
                cout << "\nData dengan nomor mahasiswa " << nim << " berhasil dihapus\n" << endl;
            }
            break;

        case '3':
            mhs.traverse();
            break;

        case '4':
            if (mhs.listEmpty())
            {
                cout << "\nList Kosong\n" << endl;
                break;
            }
            
            break;

        case '5':
            break;

        default:
            cout << "\n pilihan salah\n" << endl;
        }

    } while (ch != '5');

    return 0;
}