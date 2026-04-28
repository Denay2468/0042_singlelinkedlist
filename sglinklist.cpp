#include <iostream>
#include <string.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class linklist{
    Node *START;

    public:
    linklist()
    {
        START = NULL;
    }

    void addNode()
    {
        int NIM;
        cout << "Enter NIM: ";
        cin >> NIM;

        Node *newNode = new Node();
        newNode->data = NIM;

        if (START == NULL || NIM <= START->data){
            if ((START != NULL) && (NIM == START->data)){
                cout << "Duplicate NIM. Node not added." << endl;
                delete newNode;
                return;
            }
            newNode->next = START;
            START = newNode;
            return;
        }

        Node *previous = START;
        Node *current = START;

        while ((current != NULL) && (NIM >= current->data)){
            if (NIM == current->data){
                cout << "Duplicate NIM. Node not added." << endl;
                return;
            }
            previous = current;
            current = current->next;
        }
    }

};
