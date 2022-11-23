class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long result = 0;
        for(int i = 0; i < nums.size(); i++) {
            int minV = nums[i];
            int maxV = nums[i];
            for(int j = i+1; j < nums.size(); j++) {
                minV = min(minV, nums[j]);
                maxV = max(maxV, nums[j]);
                result += maxV - minV;
            }
        }
        return result;
    }
};