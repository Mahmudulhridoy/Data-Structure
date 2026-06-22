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

    head->next = second;
    second->next = third;
    third->next = NULL;
    cout << head->val << " " << second->val << " " << third->val << endl;

    return 0;
}