//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
private:
    class compare {
        public:
        bool operator()(pair<int,int> left, pair<int, int> right) {
            return left.first > right.first;
        }
    };
public:
    vector<int> replaceWithRank(vector<int> &arr, int N){
        // vector<int> result;
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> minHeap;
        for(int i = 0; i < arr.size(); i++) {
            minHeap.push(make_pair(arr[i], i));
        }
        int index = 1;
        while(!minHeap.empty()) {
            arr[minHeap.top().second] = index;
            int element = minHeap.top().first;
            minHeap.pop();
            if (element != minHeap.top().first) index++;
        }
        return arr;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends