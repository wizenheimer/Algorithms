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
int HDist(int a, int b)
{
    if (a == b)
    {
        return 0;
    }
    int dist = 0;
    //  preprocessing
    int max = a > b ? a : b;
    int min = a > b ? b : a;
    a = max, b = min;
    //
    while (a != 0)
    {
        int da = a % 2, db = b % 2;
        if (da != db)
        {
            dist++;
        }
        a /= 2;
        b /= 2;
    }
    return dist;
}
ll HDistOpt(v64 arr)
{
    ll sum = 0;
    ll MOD = 100000007;
    forn(i, 32)
    {
        ll nOnes = 0, nZeros = 0;
        for (auto x : arr)
        {
            if (x & (1 << i))
                nOnes++;
            else
                nZeros++;
        }
        sum += (nOnes * nZeros * 2) % MOD;
    }
    return sum % MOD;
}
void buildPairs(v64 arr)
{
    int sum = 0;
    for (size_t i = 0; i < arr.size(); i++)
    {
        for (size_t j = 0; j < arr.size(); j++)
        {
            sum += HDist(arr[i], arr[j]);
        }
    }
    cout << sum << ln;
}
int main()
{
    fast_cin();
    ll size;
    cin >> size;
    v64 arr;
    for (size_t i = 0; i < size; i++)
    {
        ll input;
        cin >> input;
        arr.push_back(input);
    }
    cout << HDistOpt(arr) << endl;
    // buildPairs(arr);
    // int sum = 0;
    // for (size_t i = 0; i < arr.size(); i++)
    // {
    //     for (size_t j = 0; j < arr.size(); j++)
    //     {
    //         int d = HDist(arr[i], arr[j]);
    //         // cout << arr[i] << " " << arr[j] << " " << d << ln;
    //         sum += d;
    //     }
    // }
    // cout << sum << ln;
    return 0;
}