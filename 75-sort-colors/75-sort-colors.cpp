class Solution {
public:
    void sortColors(vector<int>& nums) {
//         using Dutch National FLag Algorithm
        int low = 0, high = nums.size() - 1, mid = 0;
        while(mid <= high)
        {
            switch(nums[mid])
            {
                case 0 :
                    swap(nums[low++],nums[mid++]);
                    break;
                case 1 :
                    mid++;
                    break;
                case 2 :
                    swap(nums[mid],nums[high--]);                  
                    break;
            }
        }
    }
};