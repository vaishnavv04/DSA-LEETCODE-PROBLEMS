class Solution {
public:
    bool isequal(int i,int s,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(s==0)
        return true;
        if(i==nums.size())
        return false;
        if(dp[i][s]!=-1)
        return dp[i][s];
        bool nottake = isequal(i+1,s,nums,dp);
        bool take = 0;
        if(nums[i]<=s)
        take = isequal(i+1,s-nums[i],nums,dp) ;
        return dp[i][s] = take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int tsum = 0;
        for(auto &it:nums)
        tsum+=it;
        if(tsum&1)
        return 0;
        vector<vector<int>> dp(n,vector<int>(tsum,-1));
        return isequal(0,tsum/2,nums,dp);
    }
};