class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        for(int i=0;i<k-1;i++)
        colors.push_back(colors[i]);
        int i = 0 , j = 0;
        int c = 0;
        int ans = 0;
        while(j<colors.size())
        {
            if(j==0)
            {
                c++;
            }
            else
            {
                if(colors[j]!=colors[j-1])
                c++;
                else
                {
                    c = 1;
                    i = j;
                }
            }
            if(c==k)
            {
                ans++;
                c-=1;
                i++;
            }
            j++;

        }
        if(c==k)
        ans++;
        return ans;
    }
};