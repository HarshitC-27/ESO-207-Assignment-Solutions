#include <iostream>
#include <vector>
#include <array>
using namespace std;

const int maximum_value = 9999999;

bool is_right_config(const vector<int>& vec, int k, const vector<array<int, 2>>& tukde, int n);
int bin_s_and_c(vector<int>& arr, int k, const vector<array<int, 2>>& tukde, int n, const vector<int>& qeury);

int bin_s_and_c(vector<int>& arr, int k, const vector<array<int, 2>>& tukde, int n, const vector<int>& qeury) 
{
    int ptr1 = 0;
    int ptr2 = qeury.size() - 1;
    int ans = maximum_value;
    while (ptr1 <= ptr2) 
    {
        int mid = (ptr1 + ptr2) / 2;
        vector<int> temp(n);
        for (int i = 0; i < n; i++) 
        {
            temp[i] = arr[i];
        }
        for (int i = 0; i <= mid; i++) 
        {
            temp[qeury[i] - 1] = 1;
        }
        if (is_right_config(temp, k, tukde, n)) 
        {
            ans = mid;
            ptr2 = mid - 1;
        } 
        else 
        {
            ptr1 = mid + 1;
        }
    }
    return ans;
}
bool is_right_config(const vector<int>& arr, int k, const vector<array<int, 2>>& tukde, int n) 
{
    int ginti = 0;
    vector<int> pre_sum(n, 0); // Change the size here to n
    for (int i = 0; i < n; i++) 
    {
        pre_sum[i] = (i > 0 ? pre_sum[i - 1] : 0) + arr[i]; // Calculate prefix sum for index i
    }
    for (const array<int, 2>& segment : tukde) 
    {
        if (segment[0] > 1) 
        {
            if (pre_sum[segment[1] - 1] - pre_sum[segment[0] - 2] > 0) 
            {
                ginti++;
            }
        } 
        else 
        {
            if (pre_sum[segment[1] - 1] > 0) 
            {
                ginti++;
            }
        }
    }
    return ginti >= k;
}
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n, s;
        cin >> n >> s;
        vector<int> entities(n);
        for (int i = 0; i < n; i++) 
        {
            cin >> entities[i];
        }
        vector<array<int, 2>> tukde(s);
        for (int i = 0; i < s; i++) 
        {
            cin >> tukde[i][0] >> tukde[i][1];
        }
        int q, k;
        cin >> q >> k;
        vector<int> qeury(q);
        for (int i = 0; i < q; i++) 
        {
            cin >> qeury[i];
        }
        int ginti = 0;
        vector<int> pre_sum(n, 0); // Change the size here to n
        for (int i = 0; i < n; i++) 
        {
            pre_sum[i] = (i > 0 ? pre_sum[i - 1] : 0) + entities[i]; // Calculate prefix sum for index i
        }
        for (const array<int, 2>& segment : tukde) 
        {
            if (segment[0] < 1) 
            {
                if (pre_sum[segment[1] - 1] > 0) 
                {
                    ginti++;
                }
            } 
            else 
            {
                if (pre_sum[segment[1] - 1] - pre_sum[segment[0] - 2] > 0) {
                    ginti++;
                }
            }
        }
        if (ginti >= k) 
        {
            cout << "0" << endl;
        } 
        else 
        {
            int ans = bin_s_and_c(entities, k, tukde, n, qeury);
            if (ans == maximum_value) 
                cout << "-1" << endl;
            else 
                cout << ans + 1 << endl;
        }
    }
    return 0;
}