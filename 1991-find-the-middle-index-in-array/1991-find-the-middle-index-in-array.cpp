class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        auto sum = 0;
        
        for(auto i : nums) 
            sum += i;
        
        auto currSum = 0;
        auto index = 0;
        for(auto i : nums) {
            if(currSum == (sum - i - currSum)) return index;
            currSum += i;
            index++;
        }
        
        return -1;
    }
};