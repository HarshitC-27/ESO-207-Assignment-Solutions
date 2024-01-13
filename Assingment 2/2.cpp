#include <iostream>
#include <vector>
using namespace std;
struct tree_node 
{
    int value;
    int depth;
    tree_node* p1;
    tree_node* p2;
    tree_node(int val, int d) : value(val), depth(d), p1(NULL), p2(NULL) {}
};
void constructBinaryTree(vector<int>& arr, int p1, int p2, tree_node* root);

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
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) 
        {
            cin >> arr[i];
        }
        tree_node* root = new tree_node(arr[n - 1], 1);
        constructBinaryTree(arr, 0, n - 1, root);
        for (int i = 0; i < n; ++i) 
        {
            cout << arr[i]-1 << " ";
        }
        cout << endl;
    }
    return 0;
}

void constructBinaryTree(vector<int>& arr, int p1, int p2, tree_node* root) 
{
    if (p1 > p2) 
    {
        return;
    }
    int maxIndex = p1;
    for (int i = p1; i <= p2; ++i) 
    {
        if (arr[i] > arr[maxIndex]) 
        {
            maxIndex = i;
        }
    }
    arr[maxIndex] = root->depth;
    if (p1 < maxIndex) 
    {
        root->p1 = new tree_node(arr[p1], root->depth + 1);
        constructBinaryTree(arr, p1, maxIndex - 1, root->p1);
    }
    if (maxIndex < p2) 
    {
        root->p2 = new tree_node(arr[maxIndex + 1], root->depth + 1);
        constructBinaryTree(arr, maxIndex + 1, p2, root->p2);
    }
}