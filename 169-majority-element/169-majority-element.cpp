class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, result = nums[0];
        for(auto i : nums) {
            
            if(count == 0) {
                result = i;
            }
            
            if(i == result) {
                count++;
            }
            else {
                count--;
            }          
            
        }
        return result;
    }
};