#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = (int)1e5 + 5;
vector<int> graph[N];

void dfs(int i, vector<int> &visited, vector<int> &number_of_dfs, vector<int> & neecha, int parent, vector<int> g[], int &d, vector<int> &ans);

int main()
{
  // #ifndef ONLINE_JUDGE
  //   freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", stdout);
  // #endif
  int n, m;
  cin>>n>>m;
  int a[m];
  int b[m];
  for(int i=0;i<m;i++)
  {
    cin>>a[i];
  }
  for(int i=0;i<m;i++)
  {
    cin>>b[i];
  }
  for(int i=0;i<m;i++)
  {
    graph[a[i]-1].push_back(b[i]-1);
    graph[b[i]-1].push_back(a[i]-1);
  }
    vector<int> visited(n+1, 0);
    vector<int> number_of_dfs(n, -1);
    vector<int> neecha(n, -1);
    vector<int> ans(n, 0);
    for(int i=0;i<n;i++)
    {
        if(visited[i])
            continue;
        int d=0;
        dfs(i, visited, number_of_dfs, neecha, -1, graph, d, ans);
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}

void dfs(int i, vector<int> &visited, vector<int> &number_of_dfs, vector<int> & neecha, int parent, vector<int> g[], int &d, vector<int> &ans)
{
    number_of_dfs[i]=d;
    neecha[i]=d;
    visited[i]=1;
    for(auto j: g[i])
    {
        if(j!=parent)
        {
            if(visited[j])
            {
                neecha[i]=min(neecha[i], number_of_dfs[j]);
            }
            else
            {
                d++;
                dfs(j, visited, number_of_dfs, neecha, i, g, d, ans);
                neecha[i]=min(neecha[i], neecha[j]);
                if(neecha[j]<=number_of_dfs[i])
                {
                    ans[i]=1;
                    ans[j]=1;
                }
            }
        }
    }
}