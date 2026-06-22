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
void insert_at_tail(node *&head, int val)

{

    node *newnode = new node(val);
    if (head == NULL)
    {
        head = newnode;
        return; 
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;
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
    head->next = second;
    second->next = third;
    insert_at_tail(head, 200);
    insert_at_tail(head, 300);
    insert_at_tail(head, 400);
    insert_at_tail(head, 500);

    print_linked_list(head);

    return 0;
}