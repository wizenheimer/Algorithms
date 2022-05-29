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
//
ll SimpleGCD(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return SimpleGCD(b, a % b);
}
//
ll ExtendedGCD(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        // base case
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = ExtendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
//
ll SimpleLCM(ll a, ll b)
{
    return (a * b) / SimpleGCD(a, b);
}
//
ll BinaryGCD(ll a, ll b)
{
    if (a == b)
        return a;
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (~a & 1)
    {
        if (b & 1)
            return BinaryGCD(a >> 1, b);
        else
            return BinaryGCD(a >> 1, b >> 1) << 1;
    }

    if (~b & 1)
        return BinaryGCD(a, b >> 1);

    if (a > b)
        return BinaryGCD((a - b) >> 1, b);

    return BinaryGCD((b - a) >> 1, a);
}
//

int main()
{
    fast_cin();
    return 0;
}