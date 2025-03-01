class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i] == nums[i + 1])
            {
                nums[i]*=2;
                nums[i+1] = 0;
            }
        }
        for (int z = 0, cur = 0; cur < nums.size(); cur++) 
        {
            if (nums[cur] != 0) {
                swap(nums[z++], nums[cur]);
            }
        }
        return nums;
    }
};