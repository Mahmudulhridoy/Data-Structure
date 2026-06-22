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
void insert_at_any_positon(node *&head, int val, int pos)
{
    node *newNode = new node(val);
    node *temp = head;
    for (int i = 1; i < pos; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;

    temp->next = newNode;
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
    node *head = new node(10);
    node *second = new node(20);
    node *third = new node(30);
    head->next = second;
    second->next = third;

    insert_at_any_positon(head, 100, 2);
    insert_at_any_positon(head, 300, 1);
    insert_at_any_positon(head, 1499, 3);
    insert_at_any_positon(head, 145, 4);

    print_linked_list(head);
    return 0;
}