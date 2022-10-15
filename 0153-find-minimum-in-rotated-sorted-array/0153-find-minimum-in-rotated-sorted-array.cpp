class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, minVal = INT_MAX;
        
        while(left <= right) {                           
            int mid = left + (right - left)/2;
                       
            minVal = min(minVal, nums[mid]);
            
            if(nums[mid] > nums[right]) {
                // right half is unsorted
                left = mid + 1;
            } else {
                // left half is unsorted
                right = mid - 1;                
            }
        }
        return minVal;
    }
};