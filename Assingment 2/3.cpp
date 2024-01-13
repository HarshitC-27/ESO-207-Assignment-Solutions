#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
struct tree_node 
{
    int value;
    tree_node* ptr_left;
    tree_node* ptr_right;
};

tree_node* delete_node(tree_node *root,int k)
{
    if (root == NULL)
      return root;
    if (root->value > k) 
    {
      root->ptr_left = delete_node(root->ptr_left, k);
      return root;
    }
    else if (root->value < k) 
    {
      root->ptr_right = delete_node(root->ptr_right, k);
      return root;
    }
    if (root->ptr_left == NULL) 
    {
      tree_node* temporary = root->ptr_right;
      delete root;
      return temporary;
    }
    else if (root->ptr_right == NULL) 
    {
      tree_node* temporary = root->ptr_left;
      delete root;
      return temporary;
    }
    else 
    {
      tree_node* par = root;
      tree_node* after = root->ptr_right;
        while (after->ptr_left != NULL) 
        {
            par = after;
            after = after->ptr_left;
        }
        if (par != root)
          par->ptr_left = after->ptr_right;
        else
          par->ptr_right = after->ptr_right;
        root->value = after->value;
        delete after;
        return root;
    }
}

tree_node* find_node(tree_node* root,int x)
{
    if (root == NULL || root->value==x)
      return root;
    if (root->value < x)
      return find_node(root->ptr_right, x);
    return find_node(root->ptr_left, x);
}

tree_node* make_node(int value) 
{
    tree_node* new_node = new tree_node;
    new_node->value = value;
    new_node->ptr_left = nullptr;
    new_node->ptr_right = nullptr;
    return new_node;
}

tree_node* insert(tree_node* root,int x)
{
    if(!root) return make_node(x);
    if(x>root->value)
        root->ptr_right=insert(root->ptr_right,x);
    else if(x<root->value) root->ptr_left=insert(root->ptr_left,x);
    return root;
}

int main() 
{  
    int t;
    cin>>t;
    tree_node* root=NULL;
    while(t--)
    {
        int x;
        char c;
        cin>>c>>x;
        if(c=='S') root=delete_node(root,x);
        else 
        if(c=='B') root=insert(root,x);
        else if(c=='R') 
        {
            if(find_node(root,x)!=NULL) 
              cout<<"YES"<<endl;
            else 
              cout<<"NO"<<endl;
        }
    }
    return 0;
}