//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int cd[], int N, int k)
    {
        vector<int> candies(cd, cd+N);
        sort(candies.begin(), candies.end());
        int n = candies.size();
        int minCost = 0, maxCost = 0;
        for(int i = 0; i < n - i * k; i++) {
            minCost += candies[i]; 
        }
        reverse(candies.begin(), candies.end());
        for(int i = 0; i < n - i * k; i++) {
            maxCost += candies[i]; 
        }
        return {minCost, maxCost};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends