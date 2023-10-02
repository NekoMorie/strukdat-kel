#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node *next;
};

Node *linkedlist, *last;
void insertLast(Node *&linkedList, Node *&last, int n)
{
    Node *newNode;
    newNode = new Node;
    newNode->value = n;
    newNode->next = NULL;

    if (linkedList == NULL)
    {
        linkedList = newNode;
        last = linkedList;
    }
    else
    {
        last->next = newNode;
        last = newNode;
    }
}

void insertFirst(Node *&linkedList, Node *&next, int n)
{
    Node *newNode;
    newNode = new Node;
    newNode->value = n;
    newNode->next = NULL;

    if (linkedList == NULL)
    {
        linkedList = newNode;
        last = linkedList;
    }
    else
    {
        newNode->next = linkedList;
        linkedList = newNode;
    }
}
void insertAfter(Node *&linkedList, Node *&last, int n, int check)
{
    Node *newNode;
    newNode = new Node;
    newNode->value = n;
    newNode->next = NULL;

    if (linkedList == NULL)
    {
        linkedList = NULL;
        last = linkedList;
    }
    else
    {
        Node *p = linkedList;
        while (p->value != check)
        {
            p = p->next;
        }

        newNode->next = p->next;
        p->next = newNode;
    }
}
void deleteFirst(Node *&linkedList, Node *&last)
{
    if (linkedList == NULL)
    {
        cout << "Linked List Kosong ! ";
    }
    else
    {
        Node *temp;
        temp = linkedList;
        linkedList = temp->next;
        delete (temp);
    }
}

void deleteAfter(Node *&linkedList, Node *&last, int check)
{
    if (linkedList == NULL)
    {
        cout << "Linked List Is Empety!";
    }
    else
    {
        Node *temp, *p;

        p = linkedList;

        while (p->value != check)
        {
            p = p->next;
        }
        temp = p->next;
        p->next = temp->next;

        delete (temp);
    }
}

void deleteLast(Node *&linkedList, Node *&last)
{
    if (linkedList == NULL)
    {
        cout << "Linked List Kosong ! ";
    }
    else
    {
        Node *temp, *p;
        temp = last;
        p = linkedList;
        while (p->next != last)
        {
            p = p->next;
        }
        last = p;
        last->next = NULL;
        delete (temp);
    }
}

void displayList(Node *&linkedList)
{
    Node *p;

    p = linkedList;

    while (p != NULL)
    {
        cout << p->value;
        if (p->next != NULL)
        {
            cout << " << ";
        }

        p = p->next;
    }
}

int main()
{
    cout << "========== LinkedList ==========\n";
    cout << "================================\n";
    linkedlist = NULL;
    last = NULL;

    cout << "\nMenambahkan Diakhir :\n"
         << endl;
    insertLast(linkedlist, last, 10);
    insertLast(linkedlist, last, 20);
    insertLast(linkedlist, last, 30);
    displayList(linkedlist);

    cout << endl
         << "\nMenambahkan Diawal :\n"
         << endl;
    insertFirst(linkedlist, last, 5);
    insertFirst(linkedlist, last, 15);
    displayList(linkedlist);

    cout << endl
         << "\nMenambahkan Setelahnya :\n"
         << endl;
    insertAfter(linkedlist, last, 25, 20);
    displayList(linkedlist);

    cout << "\n\nMenghapus Diakhir :\n"
         << endl;
    deleteLast(linkedlist, last);
    displayList(linkedlist);

    cout << endl
         << "\nMenghapus Diawal :\n"
         << endl;
    deleteFirst(linkedlist, last);
    displayList(linkedlist);

    cout << endl
         << "\nMenghapus Setelahnya :\n"
         << endl;
    deleteAfter(linkedlist, last, 10);

    displayList(linkedlist);
    cout << endl;
    return 0;
}
