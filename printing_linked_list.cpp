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

int main()
{
    node *head = new node(10);
    node *second = new node(30);
    node *third = new node(40);
    node *fourth = new node(50);
    head->next = second;
    second->next = third;
    third->next = fourth;
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << endl; 
    }

    return 0;
}