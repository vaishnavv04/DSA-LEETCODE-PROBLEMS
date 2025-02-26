class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        pair<int,int> ans = {0,0};
        for(int i=0;i<n;i++)
        dp[i][i] = 1;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1] = 1;
                ans = {i,i+1};
            }
        }
        for(int diff=2;diff<n;diff++)
        {
            for(int i=0;i<n-diff;i++)
            {
                int j = i+diff;
                if(s[i]==s[j] && dp[i+1][j-1])
                {
                    dp[i][j] = 1;
                    ans = {i,j};
                }
            }
        }
        int i = ans.first,j=ans.second;
        return s.substr(i,j-i+1);
    }
};