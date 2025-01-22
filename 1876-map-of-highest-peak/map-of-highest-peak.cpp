class Solution {
public:
    vector<int> dir = {0,1,0,-1,0};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size() , n = isWater[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(isWater[i][j]==1) 
                {
                    q.push({i,j});
                    isWater[i][j] = 0;
                }
                else isWater[i][j] =  -1 ;
        while(!q.empty())
        {
            auto [r,c] = q.front(); q.pop();
            for(int i=0;i<4;i++)
            {
                int nr = r+dir[i] , nc = c+dir[i+1];
                if(nr>=0 && nr<m && nc>=0 && nc<n && isWater[nr][nc]==-1)
                {
                    isWater[nr][nc] = isWater[r][c] + 1;
                    q.push({nr,nc});
                }
            }
        }
        return isWater;
    }
};