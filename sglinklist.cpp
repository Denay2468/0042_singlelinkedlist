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

    bool search(int NIM)
    {
        Node *previous, *current;
        return search(NIM, &previous, &current);
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

    void traverse()
    {
        if (listEmpty())
        {
            cout << "List is empty." << endl;
        }
        else
        {
            cout << "data in the list: ";
            Node *current = START;
            while (current != NULL)
            {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }

    }

};

int main(){
    linklist list;
    int choice, NIM;

    do {
        cout << "Menu:" << endl;
        cout << "1. Add Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Node" << endl;
        cout << "4. Traverse List" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                list.addNode();
                break;
            case 2:
                cout << "Enter NIM to delete: ";
                cin >> NIM;
                if (list.delNode(NIM)) {
                    cout << "Node deleted successfully." << endl;
                } else {
                    cout << "Node not found." << endl;
                }
                break;
            case 3:
                cout << "Enter NIM to search: ";
                cin >> NIM;
                if (list.search(NIM)) {
                    cout << "Node found." << endl;
                } else {
                    cout << "Node not found." << endl;
                }
                break;
            case 4:
                list.traverse();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
