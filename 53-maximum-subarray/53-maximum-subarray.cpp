class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int glMaxima = nums[0];
        int lcMaxima = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > lcMaxima + nums[i]) {
                lcMaxima = nums[i];
            }
            else {
                lcMaxima += nums[i];
            }
            glMaxima = max(glMaxima, lcMaxima);
        }
        return glMaxima;
    }
};