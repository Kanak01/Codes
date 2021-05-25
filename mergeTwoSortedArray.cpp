#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void merge(int a[], int b[], int n, int m)
{
    int i = 0, j = 0;
    while (i < n and j < m)
    {
        if (a[i] < b[j])
        {
            cout << a[i++] << " ";
        }
        else
        {
            cout << b[j++] << " ";
        }
        
    }
    while (i < n)
            cout << a[i++] << " ";
        while (j < m)
            cout << b[j++] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    while (t--)
    {
        int arr[6] = {5,6,7,8,9,10};
        int arr2[9] = {1,2,3,4,5,6,7,8,9};
        merge(arr,arr2,6,9);
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}