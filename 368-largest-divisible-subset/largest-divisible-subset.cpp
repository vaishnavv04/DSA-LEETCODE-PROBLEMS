class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,vector<int>> m;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            m[nums[i]].push_back(nums[i]);
            vector<int> temp;
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]%nums[j]==0)
                {
                    if(temp.size()<m[nums[j]].size())
                    temp = m[nums[j]];  
                }
            }
            m[nums[i]].insert(m[nums[i]].end(),temp.begin(),temp.end());
            if(ans.size()<m[nums[i]].size())
            ans = m[nums[i]]; 
        }
        return ans;
    }
};