class Solution {
public:
    int minOperations(vector<int>& nums) {
        int c = 0;
        int n = nums.size();
        for(int i=0;i<n-2;i++)
        {
            if(nums[i]==0)
            {
                for(int j=i;j<i+3;j++)
                {
                    nums[j] = nums[j]^1;
                }
                c++;
            }
            // cout<<nums[i]<<" ";
        }
        if(nums[n-1]==0 || nums[n-2]==0)
        return -1;
        return c;
    }
};