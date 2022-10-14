//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        int maxLength = 0;
        int sum = 0;
        unordered_map<int, int> hash;
        hash[0] = -1;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            if(hash.find(sum) != hash.end()) {
                // element exists
                maxLength = max(maxLength, i - hash[sum]);
            }
            else {
                // element doesn't exist
                hash[sum] = i;
            }
        }
        return maxLength;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends