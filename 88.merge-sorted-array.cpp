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
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {

        int a = m - 1;
        int b = n - 1;
        int i = m + n - 1;

        while (a >= 0 && b >= 0)
        {
            if (nums1[a] > nums2[b])
                nums1[i--] = nums1[a--];
            else
                nums1[i--] = nums2[b--];
        }

        while (b >= 0)
        {
            nums1[i--] = nums2[b--];
        }
    }
};
// class Solution
// {
// public:
//     void rotate(v32 &arr, int pivot)
//     {
//         for (int i = arr.size() - 1; i > pivot; i--)
//         {
//             arr[i] = arr[i - 1];
//         }
//         // pivot +1 has pivot
//     }
//     void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
//     {
//         if (m * n == 0)
//         {
//             for (int i = 0; i < n; i++)
//             {
//                 nums1[i] = nums2[i];
//             }
//             return;
//         }
//         int j = 0;
//         for (int i = 0; i < m + n; i++)
//         {
//             if (nums1[i] > nums2[j])
//             {
//                 rotate(nums1, i);

//                 nums1[i] = nums2[j++];
//             }
//             if (j > n - 1)
//                 break;
//         }
//         for (int i = m + n - 1, k = n - 1; k >= j; k--, i--)
//         {
//             nums1[i] = nums2[k];
//         }
//     }
// };