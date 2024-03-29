#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next, *prev;
};

struct DoublyList
{
    Node *head, *tail;
    unsigned int _size;

    Node *createNode(int value)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));

        if (!newNode)
            return NULL;

        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        return (Node *)newNode;
    }

    void init()
    {
        head = NULL;
        tail = NULL;
        _size = 0;
    }

    bool isEmpty()
    {
        return (head == NULL && tail == NULL);
    }

    void pushFront(int value)
    {
        Node *newNode = createNode(value);

        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void pushback(int value)
    {
        Node *newNode = createNode(value);

        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
};

int main()
{
}