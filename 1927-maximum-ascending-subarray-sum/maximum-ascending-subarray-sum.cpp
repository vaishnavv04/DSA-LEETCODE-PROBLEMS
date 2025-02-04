class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum  = nums[0] , ans = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            sum+=nums[i];
            else
            sum = nums[i];
            ans = max(ans,sum);
        }
        return ans;
    }
};