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
        if (newNode)
        {
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
    }

    void pushFront(int value)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        if (newNode)
        {
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
    }

    void popFront()
    {
        if (!isEmpty())
        {
            Node *temp = head;
            head = head->next;
            free(temp);
            _size--;
        }
    }

    void popBack()
    {
        if (!isEmpty())
        {
            Node *temp = head;
            Node *nextNode = temp->next;

            if (nextNode == NULL)
            {
                free(temp);
                head = NULL;
                _size--;

                return;
            }

            while ((nextNode->next != NULL))
            {
                temp = temp->next;
            }

            free(nextNode);
            temp->next = NULL;
            _size--;
        }
    }

    void insertAt(int index, int value)
    {
        if ((head == NULL) || (index >= _size))
        {
            pushBack(value);
            return;
        }
        else if (index == 0)
        {
            pushFront(value);
            return;
        }

        Node *newNode = (Node *)malloc(sizeof(Node));
        if (newNode)
        {
            Node *temp = head;
            int i = 0;
            while ((temp->next != NULL) && (i < (index - 1)))
            {
                temp = temp->next;
                i++;
            }

            newNode->data = value;
            newNode->next = temp->next;
            temp->next = newNode;
            _size++;
        }
    }

    void removeAt(int index)
    {
        if (index == _size - 1)
        {
            popBack();
            return;
        }
        else if (index == 0)
        {
            popFront();
            return;
        }

        Node *temp = head;
        int i = 0;
        while ((temp->next != NULL) && (i < (index - 1)))
        {
            temp = temp->next;
            i++;
        }

        Node *nextTempNode = temp->next->next;
        free(temp->next);
        temp->next = nextTempNode;
        _size--;
    }

    int front()
    {
        if (!isEmpty())
            return head->data;
        else
            exit(-1);
    }

    int back()
    {
        if (!isEmpty())
        {
            Node *temp = head;

            if (temp->next != NULL)
            {
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                return temp->next->data;
            }
            else
            {
                return head->data;
            }
        }

        exit(-1);
    }

    int getAt(int index)
    {
        if (!isEmpty())
        {
            if (index == 0)
            {
                return front();
            }
            else if (index >= _size - 1)
            {
                return back();
            }

            Node *temp = head;
            int i = 0;
            while (temp->next != NULL && i < index)
            {
                temp = temp->next;
                i++;
            }

            return temp->next->data;
        }

        exit(-1);
    }

    void display()
    {
        if (!isEmpty())
        {
            Node *temp = head;

            while (temp != NULL)
            {
                cout << temp->data;
                if (temp->next != NULL)
                {
                    cout << " -> ";
                }
                temp = temp->next;
            }

            cout << "\n";
        }
    }
};

int main()
{
    List list1;
    list1.init();

    list1.pushBack(1);
    list1.pushBack(2);
    list1.pushBack(3);
    list1.pushBack(4);
    list1.pushBack(5);

    list1.popBack();

    list1.display();

    return 0;
}