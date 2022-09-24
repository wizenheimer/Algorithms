class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int i = 0, j = 1;
        for(auto itr : nums) {
            if(itr > 0) {
                result[i] = itr;
                i += 2;
            }
            else {
                result[j] = itr;
                j += 2;                
            }
        }
        return result;
    }
};