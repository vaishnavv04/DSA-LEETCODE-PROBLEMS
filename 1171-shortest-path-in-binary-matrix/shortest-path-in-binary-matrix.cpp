class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1)
        return -1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        grid[0][0] = -1;
        while(!pq.empty())
        {
            int k = pq.size();
            while(k--)
            {
                auto it = pq.top();
                int dist = it.first;
                int x = it.second.first , y = it.second.second;
                // cout<<x<<" "<<y<<endl;
                if(x==n-1 && y==n-1)
                return dist+1;
                pq.pop();
                vector<int> dx = {-1,-1,-1,0,0,1,1,1} ;
                vector<int> dy = {1,0,-1,1,-1,1,0,-1} ;
                for(int i=0;i<8;i++)
                {
                    int nx = x+dx[i] , ny = y+dy[i];
                    if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0)
                    {
                        pq.push({dist+1,{nx,ny}});
                        grid[nx][ny] = -1;
                        // cout<<nx<<" "<<ny<<endl;
                    }
                }
            }
        }
        return -1;
    }
};