class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> v(n+1);
        for(auto &edge:times)
        {
            int src = edge[0];
            int dest = edge[1];
            int time = edge[2];
            // cout<<src<<" "<<dest<<" "<<time<<endl;
            v[src].push_back({dest,time});
        }
        queue<pair<int,int>> q;
        vector<int> dist(n+1,INT_MAX);
        q.push({k,0});
        dist[k] = 0;
        dist[0] = 0;
        while(!q.empty())
        {
            auto p = q.front() ; q.pop();
            int node = p.first; 
            int time = p.second;
            for(auto edge:v[node])
            {
                int nde = edge.first;
                int wt = edge.second;
                if(time+wt<dist[nde])
                {
                    dist[nde] = time+wt;
                    q.push({nde,dist[nde]});
                }
                cout<<nde<<" "<<dist[nde]<<endl;
            }
        }
        int ans = 0;
        for(auto &it:dist)
        {
            if(it==INT_MAX)
            return -1;
            ans = max(ans,it);
        }
        return ans;
    }
};