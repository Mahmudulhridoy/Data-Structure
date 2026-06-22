#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n, q;
    cin >> n >> q;

    vector<long long int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    vector<long long int> p(n + 1);
    p[1] = v[1];
    for (int i = 2; i <= n; i++)
    {
        p[i] = p[i - 1] + v[i];
    }
    while (q--)
    {
        int l, r;
        long long int sum;
        cin >> l >> r;
        if (l == 1)
        {
            sum = p[r];
        }
        else
        {
            sum = p[r] - p[l - 1];
        }
        cout << sum << endl;
    }
}