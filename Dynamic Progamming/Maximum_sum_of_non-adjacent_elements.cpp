/*
Maximum sum of non-adjacent elements
Problem Statement: You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.
*/


// 1- Recursion

int resursive_max_sum(int ind, vector<int> &nums)
{
    if(ind == 0)
        return nums[0];
    if(ind<0)
        return 0; 
    int pick  =  nums[ind] + resursive_max_sum(ind-2,nums);
    int not_pick = 0 + resursive_max_sum(ind-1,nums);
    return max(pick,not_pick);
}

//2- Memoization
int memo_max_sum(int ind, vector<int> &nums, vector<int> &dp)
{
    if(ind == 0)
        return nums[0];
    if(ind<0)
        return 0; 
    if(dp[ind]!=-1)
      return dp[ind];
    int pick  =  nums[ind] + memo_max_sum(ind-2,nums,dp);
    int not_pick = 0 + memo_max_sum(ind-1,nums,dp);
    return dp[ind]= max(pick,not_pick);
}

//3- Tabulation
int tabulation_max_sum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n,0);
    dp[0] = nums[0];
    for(int i=1;i<n;i++)
    {
        int pick  =  nums[i] + dp[i-2];
        int not_pick = 0 + dp[i-1];
        dp[i] = max(pick,not_pick);
    } 
    return dp[n-1];
}

//4- space Optimization
int space_optimized_max_sum(vector<int> nums)
{
    int n = nums.size();
    int prev1,prev2, curr;
    prev1=nums[0];
    prev2=0;
    for(int i=1;i<n;i++)
    {
        int pick  =  nums[i] + prev2;
        int not_pick = 0 + prev1;
        curr = max(pick,not_pick);
      
      prev2=prev1;
      prev1=curr;
    } 
    return prev1;
}


int main()
{
  int n= 9;
  
  vector<int> nums{9, 1, 2, 3, 1, 3, 5, 8, 1, 9};
  
  cout<< resursive_max_sum(n-1,nums) <<endl;
  
  vector<int> dp(n,-1);
  cout<< memo_max_sum(n-1,nums,dp) <<endl;
  
  cout<< tabulation_max_sum(nums) <<endl;
  
  cout<< space_optimized_max_sum(nums);
}
