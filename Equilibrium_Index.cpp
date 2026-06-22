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

    int total_sum = b[n - 1];
    for (int i = 0; i < n; i++)
    {
        int l;
        if (i == 0)
        {
            l = 0;
        }
        else
        {
            l = b[i - 1];
        }
        int r = total_sum - b[i];
        if (l == r)
        {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
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
