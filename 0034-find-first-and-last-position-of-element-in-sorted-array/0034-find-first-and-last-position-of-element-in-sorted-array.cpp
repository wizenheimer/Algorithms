class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        
        int left = 0, right = nums.size() - 1, result = -1;
        
        // calculating first occurance
        while(left <= right) {
            int mid = left + (right - left)/2;
            if(nums[mid] == target) {
                result = mid;
                right = mid - 1;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        ans.push_back(result);
        
        
        result = -1, left = 0, right = nums.size() - 1;
        
        // calculating last occurance
        while(left <= right) {
            int mid = left + (right - left)/2;
            if(nums[mid] == target) {
                result = mid;
                left = mid + 1;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        ans.push_back(result);
        
        return ans;        
    }
};