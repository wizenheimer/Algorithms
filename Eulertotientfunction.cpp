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
ll NaiveEuler(ll num)
{
    ll result = 1;
    forsn(i, 2, num)
    {
        if (BinaryGCD(num, i) == 1)
        {
            result++;
        }
    }
    return result;
}
ll Euler2(ll num)
{
    ld result = num;
    for (size_t i = 2; i * i < num; i++)
    {
        if (num % i == 0)
        {
            while (num % i == 0)
                num /= i;

            result *= (1 - (1.0 / i));
        }
    }
    if (num > 1)
    {
        result *= (1 - (1.0 / num));
    }
    return (ll)result;
}
v64 Eulern(ll upperBound)
{
    v64 Phi(upperBound + 1);

    for (size_t i = 0; i < upperBound + 1; i++)
    {
        Phi[i] = i;
    }

    for (size_t i = 2; i < upperBound + 1; i++)
    {
        if (Phi[i] == i)
        {
            for (int j = i; j <= upperBound + 1; j += i)
            {
                Phi[j] -= Phi[j] / i;
            }
        }
    }

    return Phi;
}
v64 EulernD(ll upperBound)
{
    v64 phi(upperBound + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (size_t i = 2; i < upperBound + 1; i++)
    {
        for (long long j = 2 * i; j <= upperBound; j += i)
        {
            phi[j] -= phi[i];
        }
    }
    return phi;
}
int main()
{
    fast_cin();
    return 0;
}