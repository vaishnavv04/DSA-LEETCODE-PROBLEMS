class Solution {
public:
    bool is_sorted(vector<int> nums)
    {
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
            return false;
        }
        return true;
    }
    bool check(vector<int>& nums) {
        int n = nums.size() , i = 0;
        if(n==1)
        return 1;
        while(i<n-1 && nums[i+1]>=nums[i])
        i++;

        reverse(nums.begin(),nums.begin()+i+1);
        reverse(nums.begin()+i+1,nums.end());
        reverse(nums.begin(),nums.end());
        return is_sorted(nums);
    }
};