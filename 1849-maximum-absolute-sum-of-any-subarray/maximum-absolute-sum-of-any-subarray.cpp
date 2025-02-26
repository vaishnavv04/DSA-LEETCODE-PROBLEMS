class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int pos = 0 , neg = 0 ;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            pos+=nums[i];
            if(pos<0)
            pos = 0;
            ans = max(ans,pos);
        }
        for(int i=0;i<n;i++)
        {
            neg+=nums[i];
            if(neg>0)
            neg = 0;
            ans = max(ans,abs(neg));
        }
        return ans;
    }
};