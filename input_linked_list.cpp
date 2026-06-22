#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int val;
    node *next;
    node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
void insert_value(node *&head, node *&tail, int val)
{
    node *newnode = new node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}
void print_linked_list(node *&head)
{

    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }
}

int main()
{
    node *head = NULL;
    node *tail = NULL;
    int val;
    while (true)

    {

        cin >> val;
        if (val <= -1)
        {
            break;
        }
        insert_value(head, tail, val);
    }
    print_linked_list(head);

    return 0;
}