#include <bits/stdc++.h>
#define ll long long int
using namespace std;


// ROPE CUT PROBLEM
// int solve(int a, int b, int c, int n)
// {

//     if (n <= 0)
//     {
//         return 0;
//     }
//     int i = max(solve(a, b, c, n - a), solve(a, b, c, n - b), solve(a, b, c, n - c));
//     return (i + 1);
// }

// RECURSIVELY SUM OF ALL DIGITS OF A NUMBER 
// ll solve (ll n){
//     if(n<10){
//         return n;
//     }
//     return solve(n/10) + (n%10);

// }

// PRINT ALL SUBTRING OF A STRING 
void solve(string a,string curr ="", int index =0){
if(index == a.length()){
    cout<<curr<<" "; return;
}
solve(a,curr,index+1);
solve(a,curr+a[index],index+1);
}

int main()

{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll t = 1; //cin >> t;
    while (t--)
    {
    //   ll  n = 5569830689;               //cin>> n;
    //    // int a = 2, b = 5, c = 1; //cin>>a>>b>>c;
    //    int d = solve(n);
    //    cout<<d;
    solve("ABC");



    }
    return 0;
}