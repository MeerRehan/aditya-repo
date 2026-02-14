#leetcode - Unique Paths
"""A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?"""

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp=[1]*n
        for i in range(1,m):
            for j in range(1,n):
                dp[j]=dp[j]+dp[j-1]
        return dp[n-1]
    
    
    
    
ans=Solution()
print(ans.uniquePaths(2,7))
