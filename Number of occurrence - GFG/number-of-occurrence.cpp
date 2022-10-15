//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int target) {
	    int left = 0, right = n-1, lcr = -1, rcr = -1;
	    
	    while(left <= right) {
	        int mid = left + (right - left)/2;
	        if(target == arr[mid]) {
	            right = mid - 1;
	            lcr = mid;
	        }
	        else if(target > arr[mid]) {
	            left = mid + 1;
	        }
	        else {
	            right = mid - 1;
	        }
	    }
	    
	    if(lcr == -1) return 0;
	    
	    left = 0, right = n-1;
	    while(left <= right) {
	        int mid = left + (right - left)/2;
	        if(target == arr[mid]) {
	            left = mid + 1;
	            rcr = mid;
	        }
	        else if(target > arr[mid]) {
	            left = mid + 1;
	        }
	        else {
	            right = mid - 1;
	        }
	    }
	    
	    return rcr - lcr + 1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends