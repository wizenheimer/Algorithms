class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1, el2, c1 = 0, c2 = 0;
        
        for(auto it : nums) {
            if(it == el1) {
                c1++;
            }
            else if(it == el2) {
                c2++;
            }
            else if(c1 == 0) {
                el1 = it;
                c1++;
            }
            else if(c2 == 0) {
                el2 = it;
                c2++;
            }
            else {
                c1--;
                c2--;
            }
        }
        
        int vln = floor(nums.size()/3), f1 = 0, f2 = 0;
        for(auto it : nums) {
            if(it == el1) f1++;
            else if(it == el2) f2++;
        }
        
        vector<int> result;
        if(f1 > vln) result.push_back(el1);
        if(f2 > vln) result.push_back(el2);
        return result;
    }
};