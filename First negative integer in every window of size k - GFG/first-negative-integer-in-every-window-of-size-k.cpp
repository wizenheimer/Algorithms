//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int N, long long int k){
    deque<long long> dq;
    vector<long long> result;
    for(int left = 0, right = 0; right < N; right++) {
        int num = arr[right];
        if(num < 0) {
            dq.push_back(num);
        }
        if(right - left + 1 == k) {
            if(dq.empty()) {
                result.push_back(0);
            } else {
                result.push_back(dq.front());
            }
            if(dq.front() == arr[left])
                dq.pop_front();
            left++;
        }
    }
    return result;
 }