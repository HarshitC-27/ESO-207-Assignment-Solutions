#include <iostream>
#include <vector>

using namespace std;


long long merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right);
long long mergeSort(vector<int>& arr);

long long mergeSort(vector<int>& arr) 
{
    int n = arr.size();
    vector<int> temp(n);
    long long inv_cnt = 0;
    for (int curr_size = 1; curr_size <= n - 1; curr_size *= 2) 
    {
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) 
        {
            int mid = min(left_start + curr_size - 1, n - 1);
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);
            inv_cnt += merge(arr, temp, left_start, mid, right_end);
        }
    }
    return inv_cnt;
}
long long merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) 
{
    int i = left;
    int j = mid + 1;
    int k = left;
    long long inv_cnt = 0;
    while (j <= right && i <= mid) 
    {
        if (arr[i] <= arr[j]) 
        {
            temp[k++] = arr[i++];
        } 
        else 
        {
            temp[k++] = arr[j++];
            inv_cnt += (mid - i + 1);
        }
    }
    while (i <= mid) 
    {
        temp[k++] = arr[i++];
    }
    while (j <= right) 
    {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++) 
    {
        arr[i] = temp[i];
    }
    return inv_cnt;
}

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) 
        {
            cin >> arr[i];
        }
        long long inv_cnt = mergeSort(arr);
        cout << inv_cnt << endl;
    }
    return 0;
}
