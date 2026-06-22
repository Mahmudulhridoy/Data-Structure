#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>input(n);
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }

    cout<<endl;
    vector<int>h;
    for(int j=0; j<n; j++)
    {
        int x;
        cin>>x;
        h.push_back(x);
    }
    vector<int>v={1,2,23,2,3,45,5,2};
    vector<int>v2;
    v2=v;
    for(int i=0; i<v2.size(); i++)
    {
        cout<< v2[i]<<" ";
    }
    cout<<endl;
    for( int x: v2)
    {
        cout<< x<<" ";
    }
    cout<<endl;
    v.pop_back();
    v.push_back(133);
    for( int x: v)
    {
        cout<< x<<" ";
    }
    v.insert(v.begin()+2, 100); // irrator er use kora lagbe,  begin or end and then value
    cout<<endl;

    for( int x: v)
    {
        cout<< x<<" ";
    }
    vector<int>v3={100, 300,3};
    v.insert(v.begin()+2, v3.begin(), v3.end());
      cout<<endl;

    for( int x: v)
    {
        cout<< x<<" ";
    }
    v.erase(v.begin()+2);
     cout<<endl;

    for( int x: v)
    {
        cout<< x<<" ";
    }
    v.erase(v.begin()+2, v.begin()+5);
      cout<<endl;

    for( int x: v)
    {
        cout<< x<<" ";
    }
    //replace function works, begin, then ending , then changing value and new value
    replace(v.begin(), v.end()-5, 2, 300);
     cout<<endl;

    for( int x: v)
    {
        cout<< x<<" ";
    }
          cout<<endl;

   vector<int>:: iterator it= find(v.begin(), v.end(), 133);   //itarator indicate kore // auto likhleo cholbe
if(it==v.end())
{
cout<< "not found"<<endl;
}
else
{
    cout<<"found"<<endl;
}

cout<<v[4];
cout<<endl;

cout<<v.front();
cout<<endl;

cout<<v.back();
cout<<endl;



return 0;
}