class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(int j = 1; j < n; j++)
            if(nums[i] != nums[j])
                nums[++i] = nums[j];
        return i+1;
    }
};