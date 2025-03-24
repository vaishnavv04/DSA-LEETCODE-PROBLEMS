class Solution {
public:
    int countDays(int n, vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        long long ans = 0;
        int last = 0;
        for(int i=0;i<v.size();i++)
        {
            if(i==0)
            ans+=v[i][0]-1;
            else
            {
                if(v[i][0]>last)
                ans+=v[i][0] - last - 1;
            }
            last = max(last,v[i][1]);
        }
        ans+=n-last;
        return ans;
    }
};