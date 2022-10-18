#User function Template for python3
class Solution:

	def findMaximum(self,arr, n):
		n = len(arr)
		
		# edge cases
		if(n == 1):
		    return arr[0]
		if(arr[0] > arr[1]):
		    return arr[0]
		if(arr[n-1] > arr[n-2]):
		    return arr[n-1]
		    
		# rest of the cases
		left, right = 1, n-2
		
		while(left <= right):
		    
		    mid = left + (right - left)//2
		    
		    if(arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1]):
		        return arr[mid]
		        
	        elif(arr[mid] < arr[mid-1]):
	            right = mid - 1
	            
	        else:
	            left = mid + 1
		
		return -1


#{ 
 # Driver Code Starts
#Initial Template for Python 3





if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.findMaximum(arr, n)
        print(ans)
        tc -= 1

# } Driver Code Ends