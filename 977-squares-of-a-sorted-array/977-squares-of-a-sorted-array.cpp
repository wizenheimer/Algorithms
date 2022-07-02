class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(),1);
        int left = 0;
        int right = nums.size() - 1;
        int ptr = right;
        while(left <= right)
        {
            long long lval = abs(nums[left]);
            long long rval = abs(nums[right]);
            if(lval > rval)
            {
                result[ptr--] = lval*lval;
                left++;
            }
            else
            {
                result[ptr--] = rval*rval;
                right--;
            }
        }
        return result;
    }
};