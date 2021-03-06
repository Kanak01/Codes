#include <bits/stdc++.h>
#define ll long long int
using namespace std;

//  ----------------------------------------------------------------
//!  FUNCTION FOR CHECKING ANAGRAM
//  ----------------------------------------------------------------
bool anagram(string a, string b)
{
    int arr[256] = {0};
    if (a.length() != b.length())
    {
        return false;
    }
    for (int i = 0; i < a.length(); i++)
    {
        arr[a[i]]++;
    }
    for (int i = 0; i < b.length(); i++)
    {
        arr[b[i]]--;
    }
    int j = 0;
    if (accumulate(arr, arr + 256, j) != 0)
    {
        return false;
    }
    return 1;
}

//----------------------------------------------------------------
//? FUNCTION FOR CHECKING LEFTMOST REPEATING CHARACTER
//----------------------------------------------------------------
int firstRepeat(string s)
{
    int ans = INT_MAX;
    int arr[256];
    for (int i = 0; i < 256; i++)
    {
        arr[i] = -1;
    }
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (arr[s[i]] == -1)

            arr[s[i]] = i;

        else
        {
            ans = arr[s[i]];
        }
    }
    return (ans == INT_MAX) ? -1 : ans;
}
//----------------------------------------------------------------
//* FUNCTION FOR CHECKING LEFTMOST NON - REPEATING CHARACTER
//----------------------------------------------------------------

int firstNonRepeat(string s)
{
    int ans = INT_MAX;
    int arr[256];
    for (int i = 0; i < 256; i++)
    {
        arr[i] = -1;
    }
    for (int i = 0; i<s.length(); i++)
    {
        if (arr[s[i]] == -1) arr[s[i]] = i;
        else  arr[s[i]] = -2;
        
    }
    for (int i = 0; i < 256; i++){
        if(arr[i] >= 0) ans = min(ans,arr[i]);
    }
    return (ans == INT_MAX) ? -1 : ans;
}

//*--------------------------------------------------------------
//  !Naive Algorithm checking for every char and resting again from previoulsy checked element
//  TODO:  time complexitiy is ((m-n+1) * n)
//*-------------------------------------------------------------
//  !Optimized Naive Algorithm checking for every distinct char and reseting at the end of 
//  ?checked string time complexity is O(n).
//*-------------------------------------------------------------
//  !Rabin Karp Algorithm checking hash of string and if hash match then checking elements
//  ?*worst case time complexity is same as naive && average case is O(n).
//*-------------------------------------------------------------
//  !KMP Algorithm is good
// 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    while (t--)
    {
        
    }
    return 0;
}