class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size(),ans=0;
        unordered_map<int,int> mc , mr;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    mc[j]++;
                    mr[i]++;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((grid[i][j]==1) && (mr[i]>1 || mc[j]>1))
                ans++;
            }
        }
        return ans;
    }
};