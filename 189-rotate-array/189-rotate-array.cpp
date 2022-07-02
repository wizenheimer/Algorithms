class Solution {
public:
    void reverse(vector<int>& arr,int start,int end)
    {
        while(start <= end)
        {
            swap(arr[start++],arr[end--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        reverse(nums,0,len - k - 1);
        reverse(nums,len - k, len - 1);
        reverse(nums,0,len - 1);
    }
};