class Solution:
    def findPeakElement(self, nums: List[int]) -> int:        
        # variable declaration
        n = len(nums)
        
        # edge cases 1/3
        if n == 1:
            return 0
        
        # edge cases 2/3
        if nums[0] > nums[1]:
            return 0
        
        # edge cases 3/3
        if nums[-1] > nums[-2]:
            return n - 1
                
        left, right = 1, n-2
        
        while left <= right :
            # evaluating middle index
            mid = left + (right - left)//2
            
            # generic case
            if nums[mid] > nums[mid - 1] and nums[mid] > nums[mid + 1]:
                return mid
            elif nums[mid] < nums[mid - 1]:
                right = mid - 1
            else:
                left = mid + 1
        
        # returning dummy element
        return -1
        