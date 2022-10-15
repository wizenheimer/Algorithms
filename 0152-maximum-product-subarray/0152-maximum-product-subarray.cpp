class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int result = nums[0];
        int maxK = nums[0], minK = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < 0) swap(maxK, minK);
            
            maxK = max(nums[i], maxK * nums[i]);
            minK = min(nums[i], minK * nums[i]);
            
            result = max(maxK, result);
        }
        
        return result;
    }
};