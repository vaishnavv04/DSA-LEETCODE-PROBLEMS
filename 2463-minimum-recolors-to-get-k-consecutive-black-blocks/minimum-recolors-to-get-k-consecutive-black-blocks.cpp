class Solution {
public:
    int minimumRecolors(string s, int k) {
        int i = 0;
        int j = 0;
        int n = s.size();
        int c = 0;
        int mc = INT_MAX;
        while(j<n)
        {
            if(s[j]=='W')
            c++;
            if(j-i+1<k)
            j++;
            else
            {
                mc = min(mc,c);
                if(s[i]=='W')
                c--;
                i++;j++;
            }
        }
        return mc;
    }
};