class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int j = m - 1, k = n - 1, tar = m+n-1;
        
        while(j >= 0 && k >=0)
        {
            nums1[tar--] = (nums1[j] > nums2[k]) ? nums1[j--] : nums2[k--];
        }
        
        while(j >= 0)
        {
            nums1[tar--] = nums1[j--];
        }
        
        while(k >= 0)
        {
            nums1[tar--] = nums2[k--];
        }
    }
};