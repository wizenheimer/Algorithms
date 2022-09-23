class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = nums.size(), i = 0;
        for(i = 0; i < nums.size(); i++) {
            x = x ^ i ^ nums[i];
        }
        return x;
    }
};