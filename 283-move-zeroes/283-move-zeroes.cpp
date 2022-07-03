class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCount = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                zeroCount += 1;
            }
            else
            {
                swap(nums[i],nums[i-zeroCount]);
            }
        }
    }
};