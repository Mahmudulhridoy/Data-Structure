#include <bits/stdc++.h>
using namespace std;

void running_sum(int n, vector<int> &a)
{
    vector<int> b(n);
    b[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        b[i] = b[i - 1] + a[i];
    }
    for (int x : b)
    {
        cout << x << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    running_sum(n, v);
}
