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
void insert_at_head(node *&head, int val)
{
    node *newNode = new node(val);
    newNode->next = head;
    head = newNode;
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

    insert_at_head(head, 100);
    insert_at_head(head, 300);
    insert_at_head(head, 1499);
    insert_at_head(head, 145);

    print_linked_list(head);
    return 0;
}