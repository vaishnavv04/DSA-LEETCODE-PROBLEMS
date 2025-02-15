class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>
                            ,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
            auto p = pq.top() ; pq.pop();
            int maxdiff = p.first;
            auto [x,y] = p.second;
            if(x==m-1 && y==n-1)
            return maxdiff;
            vector<int> dx = {-1,0,0,1};
            vector<int> dy = {0,1,-1,0};

            for(int i=0;i<4;i++)
            {
                int nx = x+dx[i] , ny = y+dy[i];
                if(nx>=0 && ny>=0 && nx<m && ny<n && grid[x][y]!=-1)
                {
                    int diff = max(abs(grid[x][y]-grid[nx][ny]),maxdiff);
                    if(diff<dist[nx][ny])
                    {
                        dist[nx][ny] = diff;
                        pq.push({diff,{nx,ny}});
                    }
                }
            }
            grid[x][y] = -1;
        }
        return pq.top().first;
    }
};