#include <bits/stdc++.h>
#define ll long long int
using namespace std;
/*
*                BUBBLE SORT
todo             SELECTION SORT
*                INSERTION SORT
todo             MERGE SORT
*                QUICK SORT      {In file named partition algorithm}.
todo             HEAP SORT
*                COUNTING SORT
todo             RADIX SORT
*                BUCKET SORT
*/

/*----------------------------------------------------------------
//todo                  BUBBLE SORT Algorithm
------------------------------------------------------------------*/
void bubbbleSort(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        bool swapeed = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapeed = true;
            }
        }
        if (swapeed == false)
            break;
    }
}

//------------------------------------------------------------------------------
//todo               SELECTION SORT ALGORITHM
//------------------------------------------------------------------------------

void selectionSort(int arr[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr[i], arr[min]);
    }
}

//------------------------------------------------------------------------------
//todo               INSERTION SORT ALGORITHM
//------------------------------------------------------------------------------

void insertSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 and arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
//*  Insertion sort is very often used in hybrid sorting system in library implimentation
//*  it is best algorithm for small no of elememts its time complexitiy is O(n^2) in the worst case
//*  but its O(n) in average case soo when merge sort and quicksort have very small input insertion
//*  sort is recommended.

//------------------------------------------------------------------------------
//todo                       Merge Sort Algorithm
//------------------------------------------------------------------------------

void merge(int arr[], int l, int m, int h)
{
    int n1 = m - l + 1, n2 = h - m;

    int a[n1], b[n2];

    for (int i = 0; i < n1; i++)
        a[i] = arr[l + i];

    for (int i = 0; i < n2; i++)
        b[i] = arr[i + m + 1];

    int i = 0, j = 0, k = l;

    while (i < n1 and j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k++] = a[i++];
        }
        else
        {
            arr[k++] = b[j++];
        }
    }
    while (i < n1)
        arr[k++] = a[i++];
    while (j < n2)
        arr[k++] = b[j++];
} //?  MERGE Function

void mergeSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int mid = l + (h - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}



//* --------------------------------Print function--------------------------------------------//

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
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
    ll t = 1; //cin >> t;
    while (t--)
    {
        int n = 8;
        int arr[n] = {5, 4, 7, 3, 6, 1, 8, 2};
        print(arr, n);
        // selectionSort(arr, n);
        // print(arr, n);
        mergeSort(arr, 0, 8);
        print(arr, n);
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}