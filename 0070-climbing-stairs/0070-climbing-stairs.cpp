class Solution {
public:
    unordered_map<int,int> hash;
    int climbStairs(int n) {
        // base case
        if(n == 0)
            return 1;
        if(n < 0) 
            return 0;
        
        // memoization
        if(hash.find(n) == hash.end()) {
            hash[n-1] = climbStairs(n-1);
            hash[n-2] = climbStairs(n-2);
            hash[n] = hash[n-1] + hash[n-2];
        }       
        
        return hash[n];
    }
};