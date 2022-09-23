class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int lMax = 0, gMax = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                lMax += 1;
            }
            else {
                gMax = max(lMax, gMax);
                lMax = 0;
            }
        }
        gMax = max(lMax, gMax);
        return gMax;
    }
};