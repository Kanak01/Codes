#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// ----------------------------------------------------------------
//*                    BINARY SEARCH CODE
//  ----------------------------------------------------------------

int binarySearch(int arr[], int n, int a)
{

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == a)
        {
            return mid;
            break;
        }
        else if (arr[mid] < a)    low = mid+1;
        else                      high = mid-1;
    }
    return -1;
}

//***********************************************************
// !           RECCUSRIVE BINARY SEARCH
//***********************************************************

int recursiveBSearch(int arr[], int low, int high, int a)
{   if (low >= high) return -1;
    int mid = (low + high) / 2;

    if (arr[mid] == a)        return mid;
    else if (arr[mid] < a)    return recursiveBSearch(arr, mid + 1, high, a);
    else                      return recursiveBSearch(arr, low, mid - 1, a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    while (t--)
    {
        int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        cout << arr[recursiveBSearch(arr,0,9,8)];
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}