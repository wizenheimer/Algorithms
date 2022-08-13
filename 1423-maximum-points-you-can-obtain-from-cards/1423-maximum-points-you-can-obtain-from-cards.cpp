class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> frontSum(n+1, 0), rearSum(n+1, 0);
        
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            frontSum[i+1] = sum;
        }
        
        sum = 0;
        for(int i = n-1; i >= 0; i--) {
            sum += arr[i];
            rearSum[i] = sum; 
        }
        
        reverse(rearSum.begin(), rearSum.end());
        
        int result = 0;
        for(int i = 0; i <= k; i++) {
            result = max(result, frontSum[i] + rearSum[k-i]); 
        }
        
        return result;
    }
};