#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define int long long

using namespace std;

const int max_val = (int) 1e5+5;

vector<int> a[max_val];
int color[max_val];

bool dfs(int v, int c)
{
    color[v]=c;
    for(int u : a[v])
    {
        if(color[u]==c)
            return false;
        if(color[u]==0 && !dfs(u, 3-c))
            return false;
    }
    return true;
}
signed main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int n, m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x, y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(color[i]==0)
        {
            if(!dfs(i, 1))
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i=1; i<=n;i++)
    {
        cout<<color[i]<<" ";
    }
    return 0;
}