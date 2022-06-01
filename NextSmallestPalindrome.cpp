#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

bool isPalin(int n)
{
    int r = 0, num = n;
    while (n > 0)
    {
        int d = n % 10;
        r = r * 10 + d;
        n /= 10;
    }
    return num == r;
}
int reverseNum(int n)
{
    int result = 0;
    while (n > 0)
    {
        int d = n % 10;
        result = d + result * 10;
        n /= 10;
    }
    return result;
}
//
string Solve(string str)
{
    long long n = str.size();
    long long num = atol(str.c_str());
    if (isPalin(num))
    {
        num += 1;
        str = to_string(num);
        n = str.size();
    }
    if (n % 2 != 0)
    {
        // odd case
        // get numbers
        long long mid = str.at(n / 2) - '0';
        long long lhs = atol(str.substr(0, n / 2).c_str());
        if (mid == 9)
        {
            lhs++;
            mid = 0;
        }
        long long revLhs = reverseNum(lhs);
        long long rhs = atol(str.substr(1 + n / 2, n / 2).c_str());
        // cases
        if (revLhs < rhs)
        {
            mid++;
        }
        str = to_string(lhs) + to_string(mid) + to_string(revLhs);
    }
    else
    {
        // even case
        //  get numbers
        long long lhs = atol(str.substr(0, n / 2).c_str());
        long long revLhs = reverseNum(lhs);
        long long rhs = atol(str.substr(n / 2, n / 2).c_str());
        // cases
        if (revLhs < rhs)
        {
            lhs += 1;
            revLhs = reverseNum(lhs);
        }
        str = to_string(lhs) + to_string(revLhs);
    }
    return str;
}

int main()
{
    fast_cin();
    string str;
    cin >> str;
    // cout << Solve(str) << endl;
    return 0;
}