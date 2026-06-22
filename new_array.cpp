#include<bits/stdc++.h>
using namespace std;

void array_concate(int n, vector<int>&a, vector<int>&b)
{
vector<int>c;
for(int i=0; i<n; ++i)
{
    c.push_back(b[i]);
}

for(int i=0; i<n; ++i)
{
    c.push_back(a[i]);
}
for(int i=0l; i<2*n; i++)
{
    cout<<c[i]<<" ";
}
cout<<endl;
}
int main()
{

int n;
cin>>n;
vector<int>v(n);
vector<int>v2(n);
for(int i=0; i<n; i++)
{
      cin>>v[i];

}
for(int i=0; i<n; i++)
{
      cin>>v2[i];

}
array_concate(n,v,v2);


}