#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int m;
    cin >> m;
    vector<int> v2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> v2[i];
    }

    int x, z;
    z = m + n;
    cin >> x;
    vector<int> v3(z);
    for (int i = 0; i < x; i++)
    {
        v3[i] = v[i];
    }
    for (int i = 0; i < m; i++)
    {
        v3[x + i] = v2[i];
    }

    for (int i = x; i < n; i++)
    {
        v3[m + i] = v[i];
    }

    for (int i = 0; i < z; i++)
    {
        cout << v3[i] << " ";
    }
}