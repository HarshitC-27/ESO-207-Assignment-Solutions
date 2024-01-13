#include <iostream>
using namespace std;
int main() 
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        long long k;
        cin >> n >> k;
        long long total[1000001] = {0};
        // long long heights[n];
        long long height;
        for (int i = 0; i < n; ++i) 
        {
            cin>>height;
            total[height]++;
        }
        long long ans = 0;
        for(int i = 1000000; i>0;)
        {
            if(total[i]==0) 
            {
                i--;
                continue;
            }
            else if(k>=i)
            {
                total[i]--;
                total[i-1]++;
                k-=i;
            }
            else
            {
                ans = i; 
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}