class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int eves = 0 ,  odds = 0 , ps = 0;
        int ans = 0;
        int MOD = 1e9+7;
        for(int i=0;i<n;i++)
        {
            ps+=arr[i];
            if(ps&1)
            {
                ans=(ans+eves+1)%MOD;
                odds++;
            }
            else
            {
                ans=(ans+odds)%MOD;
                eves++;
            }
        }
        return ans%MOD;
    }
};