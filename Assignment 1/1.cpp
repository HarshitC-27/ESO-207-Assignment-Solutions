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
    while(t--)
    {
        int n;
        cin >> n;
        long long pre_sum[n];
        long long max_sum[n];
        for (int i = 0; i < n; ++i) 
        {
            cin >> pre_sum[i];
            if (i > 0) 
            {
                pre_sum[i] += pre_sum[i - 1];
            }
        }
        max_sum[n - 1] = pre_sum[n - 1];
        long long maxSum = max_sum[n - 1];
        for (int i = n - 2; i >= 0; --i) 
        {
            maxSum = max(maxSum, pre_sum[i]);
            max_sum[i] = maxSum;
        }
        for (int i = 0; i < n; ++i) 
        {
            max_sum[i] -= (i > 0 ? pre_sum[i - 1] : 0);
            cout << max_sum[i] << " ";
        }
        cout<<endl;
    }
    return 0;
}
