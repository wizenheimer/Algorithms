class Solution {
public:
    int binSearch(vector<int> &nums,int left,int right,int target)
    {
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& input, int target) 
    {
        int len = input.size();
        for(int i = 0; i < input.size(); i++)
        {
            int value = input[i];
            int index = binSearch(input, i+1, len-1, target-value);
            if(index != -1)
                return {i+1, index+1};
        }
        return {0,0};
    }
};