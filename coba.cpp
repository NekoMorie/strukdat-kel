#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node *next;
};

int main()
{
    int array[5];
    Node *head = nullptr;
    for (int i = 1; i <= 5; i++)
    {
        Node *newNode = new Node;
        newNode->data = i;
        newNode->next = head;
        head = newNode;
    }

    for (int i = 0; i < 5; i++)
    {
        array[i] = i + 1;
    }

    Node *currentNode = head;
    cout << "Linked List: ";
    while (currentNode != nullptr)
    {
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    cout << endl;

    cout << "Array: ";
    for (int i = 0; i < 5; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
