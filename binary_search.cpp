#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, q;
  cin >> n >> q;
  int v[n];
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  sort(v, v + n);
  int found = 0;

  for (int i = 0; i < q; i++)
  {
    int l, r;
    int found = 0;
    l = 0;
    r = n - 1;
    int mid;

    int f;
    cin >> f;
    while (l <= r)
    {
      mid = l + (r - l) / 2;

      if (v[mid] < f)
      {
        l = mid + 1;
      }
      else if (v[mid] == f)
      {
        found = 1;
        break;
      }

      else
      {
        r = mid - 1;
      }
    }
    if (found == 0)
    {
      cout << "not found" << endl;
    }
    else
    {
      cout << "found" << endl;
    }
  }
}
