#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct List
{
    Node *head;
    unsigned int _size;

    void init()
    {
        head = NULL;
        _size = 0;
    }

    bool isEmpty()
    {
        return (head == NULL);
    }

    void pushBack(int value)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = value;
        newNode->next = NULL;
        _size++;

        if (isEmpty())
            head = newNode;
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void pushFront(int value)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = value;
        _size++;

        if (isEmpty())
            head = newNode;
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void delateNode(int value)
    {
        Node *temp = head;
        Node *check = temp->next;
        Node *nextNode = check->next;
        while (temp->next != NULL)
        {
            if (check->data == value)
            {
                if (check->next == NULL)
                {
                    temp->next = NULL;
                }
                else
                {
                    temp->next = nextNode;
                }
            }
            temp = temp->next;
        }
    }
};

int main()
{
}