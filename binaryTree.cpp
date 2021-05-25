#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class node
{
public:
    node *left;
    node *right;
    int key;
    node(int k)
    {
        key = k;
        ;
        left = right = NULL;
    }
};

void inOrderTravesal(node *root)
{
    if (root != NULL)
    {
        inOrderTravesal(root->left);
        cout << (root->key) << " ";
        inOrderTravesal(root->right);
    }
}

void preOrderTravesal(node *root)
{
    if (root != NULL)
    {
        cout << (root->key) << " ";
        preOrderTravesal(root->left);
        preOrderTravesal(root->right);
    }
}

void postOrderTravesal(node *root)
{
    if (root != NULL)
    {
        postOrderTravesal(root->left);
        postOrderTravesal(root->right);
        cout << (root->key) << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t = 1; //cin >> t;
    while (t--)
    {
        node *root = new node(20);                           //root 20
        root->left = new node(10);                        //root 10     30  
        root->right = new node(30);                    //     40    60
        root->left->right = new node(60);      // inoreder 40 10 60 20 30
        root->left->left = new node(40);      //  postorder 40 60 10 30 20
        inOrderTravesal(root);                //  pre 20 10 40 60 30
        cout << endl;
        preOrderTravesal(root);
        cout << endl;
        postOrderTravesal(root);
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}