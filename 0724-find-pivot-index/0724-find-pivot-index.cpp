class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        auto sum = 0;
        for(auto num : nums)
            sum += num;
        
        auto currSum = 0;
        auto index = 0;
        
        for(auto num : nums) {
            if(currSum == (sum - num - currSum)) return index;
            index += 1;
            currSum += num;
        }
        
        return -1;
    }
};