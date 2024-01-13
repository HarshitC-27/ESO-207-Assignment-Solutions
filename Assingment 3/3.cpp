#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

void dfs_new(int u, int p, vector<vector<int> >&memory, vector<int> &lev, int lo, vector<int> graph[]);

int least_common_ancestor(int u, int v, int lo, vector<int> &lev, vector<vector<int> > &memory);

int dfs(int i, vector<int> graph[], vector<int> &a, vector<int> &b, int par);

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int n, k;
    cin>>n>>k;

    vector<int> graph[n];
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    vector<int> a1(n, 0);
    vector<int> b1(n, 0);

    for(int i=0; i<n-1; i++)
        cin>>a1[i];
    for(int i=0;i<n-1; i++)
        cin>>b1[i];
    for(int i=0; i<n-1; i++)
    {
        graph[a1[i]-1].push_back(b1[i]-1);
        graph[b1[i]-1].push_back(a1[i]-1);
    }
    int lower= (int) ceil(log2(n));
    vector<vector<int> > memory(n+1, vector<int> (lower+1, -1));
    vector<int> lev(n+1);
    lev[0]=0;
    dfs_new(0, 0, memory, lev, lower, graph);
    for(int j=0;j<k;j++)
    {
        int x, y;
        cin>>x>>y;
        int kappa=least_common_ancestor(x-1, y-1, lower, lev, memory);
        b[kappa]+=1;
        a[x-1]++;
        a[y-1]++;
    }
    dfs(0, graph, a, b, -1);
    
    for(int i=0;i<n;i++)
    {
        cout<<a[i]-b[i]<<" ";
    }
    return 0;
}

void dfs_new(int u, int p, vector<vector<int> >&memory, vector<int> &lev, int lo, vector<int> graph[])
{
    memory[u][0]=p;
    for(int i=1; i<=lo; i++)
    {
        memory[u][i] = memory[memory[u][i-1]][i-1];
    }
    for(int v: graph[u])
    {
        if(v!=p)
        {
            lev[v] = lev[u] + 1;
            dfs_new(v, u, memory, lev, lo, graph);
        }
    }
}

int least_common_ancestor(int u, int v, int lower, vector<int> &lev, vector<vector<int> > &memory) 
{
    if(lev[u] < lev[v])
        swap(u, v);
    for(int i=lower; i>=0; i--)
    {
        if( ( lev[u]-pow(2, i)) >= lev[v] )
            u=memory[u][i];
    }

    if(u==v)
    {
        return u;
    }

    for(int i=lower; i>=0; i--)
    {
        if(memory[u][i] != memory[v][i])
        {
            u=memory[u][i];
            v=memory[v][i];
        }
    }
    return memory[u][0];  
}

int dfs(int i, vector<int> graph[], vector<int> &a, vector<int> &b, int par)
{
    for(auto j: graph[i])
    {
        if(j!=par)
        {
            a[i]+=dfs(j, graph, a, b, i);
        }
    }
    return a[i]-2*b[i];
}