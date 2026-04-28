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

        newNode->next = current;
        previous->next = newNode;
    }

    bool listEmpty()
    {
        return START == NULL;
    }

    bool search(int NIM, Node **previous, Node **current)
    {
        *previous = START;
        *current = START;

        while (*current != NULL && NIM != (*current)->data)
        {
            *previous = *current;
            *current = (*current)->next;
        }

        return (*current != NULL);
    }

    bool delNode(int NIM)
    {
        Node *previous, *current;
        if (!search(NIM, &previous, &current))
            return false;

        if (current == START)
            START = START->next;
        else
            previous->next = current->next;

        delete current;
        return true;
    }

};
