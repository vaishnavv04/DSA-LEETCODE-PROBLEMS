class Solution {
public:
    int maxDepth(string s) {
        int c = 0,ans=0;
        for(auto ch:s)
        {
            if(ch=='(')
            c++;
            else if(ch==')')
            c--;
            ans = max(ans,c);
        }
        return ans;
    }
};