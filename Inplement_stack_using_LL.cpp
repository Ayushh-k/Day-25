#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int d) : data(d), next(NULL), prev(NULL) {};
};

struct Stack
{
    node *top = NULL;
};

bool isempty(Stack &s)
{
    return s.top == NULL;
}

void Push(Stack &s, int d)
{
    node *newnode = new node(d);
    if (isempty(s))
    {
        s.top = newnode;
        return;
    }

    s.top->next = newnode;
    newnode->prev = s.top;
    s.top = newnode;
}

void Pop(Stack &s)
{
    if (isempty(s))
    {
        cout << "Stack underflow" << endl;
        return;
    }

    node *temp = s.top;
    s.top = s.top->prev;
    if (s.top != NULL)
    {
        s.top->next = NULL;
    }
    temp->prev = NULL;
    delete temp;
}

int peek(Stack &s)
{
    if (isempty(s))
    {
        cout << "Stack underflow" << endl;
        return INT_MIN;
    }

    return s.top->data;
}

int main()
{
    Stack s;
    int max_size;
    cout << "Enter the size of stack: ";
    cin >> max_size;

    for (int i = 0; i < max_size; i++)
    {
        int d;
        cin >> d;
        Push(s, d);
    }

    while (!isempty(s))
    {
        cout << peek(s) << endl;
        Pop(s);
    }

    return 0;
}