class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        dp = [[0,0]]
        f = lambda x: dp[bisect_left(dp,[x+1])-1][1]
        for e, s, p in sorted(zip(endTime,startTime, profit)):            
            dp.append([e, max(f(e),p+f(s))])               
        return dp[-1][1]        