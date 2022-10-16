//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> arr, long long n, long long target){
        
        long long left = 0, right = n - 1;
        int index = 0;
        
        while(left <= right) {
            long long mid = left + (right - left)/2;
            
            if(arr[mid] == target) {
                index = mid;
                break;
            } else if(arr[mid] < target) {
                left = mid + 1;
                index = (arr[mid] > arr[index]) ? mid : index;
            } else if(arr[mid] > target) {
                right = mid - 1;
            }
        }
        
        if(index == 0 && arr[index] > target) return -1;
        
        return index;
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends