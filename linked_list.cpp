#include <stdio.h>
#include <iostream>

using namespace std;


struct Node
{
    int val;
    Node *next;

};

void print(Node *current);


Node *head;
Node *tail;


void insert(int val)
{
    if(head == NULL)
    {
        head = new Node;
        head->val = val;
        head->next = NULL;
        tail = head;
    }
    else
    {
        Node *temp = new Node;
        temp->val = val;
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
        cout << "inserted\n";

    }
}

void deleteL(int val)
{
    Node *current = head;
    Node *prev;
    while(current)
    {
        //cout << "#";
        if(current->val == val)
        {
            if(current == head)
            {
                head = head->next;
            }
            else
            {
                //cout << prev->val << " * " << current->next->val << endl;

                prev->next = current->next;

            }
        }
        prev = current;
        current = current->next;


    }
}

Node *head1, *tail1;

void insertBoo(int val)
{
    if(head1 == NULL)
    {
        head1 = new Node;
        head1->val = val;
        head1->next = NULL;
        tail1 = head1;
    }
    else
    {
        Node *temp = new Node;
        temp->val = val;
        temp->next = NULL;
        tail1->next = temp;
        tail1 = temp;
        cout << "inserted\n";
    }
}

void manipulate(int x)
{
    head1 = NULL;
    Node *current = head;
    int counter = 0;
    while(counter < 3)
    {
        if(current->val < x && counter == 0)
        {
            insertBoo(current->val);
        }

        if(current->val == x && counter == 1)
        {
            insertBoo(current->val);
        }

        if(current->val > x && counter == 2)
        {
            insertBoo(current->val);
        }
        current = current->next;
        if(current == NULL)
        {
            current = head;
            counter++;
        }
    }

    print(head1);


    //head = first;

}



void print(Node *current)
{
    //Node *current = head;
    while(current)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    head = NULL;
    insert(1);
    insert(4);
    insert(3);
    insert(2);
    insert(5);
    insert(2);
    insert(3);
    //deleteL(50);
    int x = 3;
    manipulate(x);
    print(head);


    return 0;
}
