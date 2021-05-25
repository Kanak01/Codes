#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int lomutoPartition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int j = l - 1;
    for (int i = l; i <= h - 1; i++)
    {
        if (arr[i] < pivot)
        {
            j++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[j + 1], arr[h]);
    return (j + 1);
}
//todo:     Lomuto partion place the pivot in sorted postion.

int hoarePartition(int arr[], int l, int h, int p)
{
    swap(arr[p], arr[l]);
    int pivot = arr[l];
    int i = l - 1, j = h + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}
//todo:    Hoare's partition uses less comparsion.

void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = lomutoPartition(arr, l, h);
        quickSort(arr, l, p - 1);  //? In hoare algo we put p insted of p-1.
        quickSort(arr, p + 1, h);
    }
}//! this is lomutoPartition implimentation.

//todo: Hoare's partition is some studies found to be three times's faster than lomuto Partition.

//? Recommended that we should pick a random pivot by random function and then use lomato or
//? hoars algo for partition that should eliminate adverse patteren from algo.

//* --------------------------------Print function--------------------------------------------//

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++) 1
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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
        int arr[] = {2, 4, 5, 1, 3, 6, 8, 1, 79, 9};
        print(arr, 10);
        lomutoPartition(arr, 0, 9);
        print(arr, 10);
        hoarePartition(arr, 0, 9, 2);
        print(arr, 10);
        quickSort(arr, 0, 9);
        print(arr, 10);
        print(arr, 10);
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}