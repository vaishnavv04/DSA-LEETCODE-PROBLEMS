class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1])
        return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        int lvl = 0;
        grid[0][0] = -1;
        while(!q.empty())
        {
            int k = q.size();
            while(k--)
            {
                int x = q.front().first , y = q.front().second;
                cout<<x<<" "<<y<<endl;
                if(x==n-1 && y==n-1)
                return lvl+1;
                q.pop();
                vector<int> dx = {-1,-1,-1,0,0,1,1,1} ;
                vector<int> dy = {1,0,-1,1,-1,1,0,-1} ;
                for(int i=0;i<8;i++)
                {
                    int nx = x+dx[i] , ny = y+dy[i];
                    if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0)
                    {
                        if(nx==n-1 && ny==n-1)
                        return lvl+2;
                        q.push({nx,ny});
                        grid[nx][ny] = -1;
                        // cout<<nx<<" "<<ny<<endl;
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};