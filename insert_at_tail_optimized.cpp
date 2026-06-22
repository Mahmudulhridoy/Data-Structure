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
void insert_at_tail(node *&head, node *&tail, int val)

{

    node *newnode = new node(val);
    if (head == NULL)
    {
        head = newnode;
        return;
    }

    tail->next = newnode;
    tail = newnode;
}
void print_linked_list(node *head)
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
    node *head = new node(20);
    node *second = new node(30);
    node *third = new node(40);
    node *tail = new node(50);
    head->next = second;
    second->next = third;
    third->next = tail;
    insert_at_tail(head, tail, 200);
    insert_at_tail(head, tail, 300);
    insert_at_tail(head, tail, 400);
    insert_at_tail(head, tail, 500);

    print_linked_list(head);

    return 0;
}