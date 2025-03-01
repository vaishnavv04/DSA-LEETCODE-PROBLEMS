class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long M = 1e9+7;
        vector<vector<pair<int,int>>> adj(n);
        for(auto &edge:roads)
        {
            int src = edge[0];
            int dest = edge[1];
            int time = edge[2];
            adj[src].push_back({dest,time});
            adj[dest].push_back({src,time});
        }
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n,LONG_MAX);
        vector<int> ways(n);
        pq.push({0,0});
        dist[0] = 0;
        ways[0] = 1;
        while(!pq.empty())
        {
            auto p = pq.top() ; pq.pop();
            long long node = p.second; 
            long long time = p.first;
            for(auto edge:adj[node])
            {
                long long adjnode = edge.first;
                long long wt = edge.second;
                if(time+wt<dist[adjnode])
                {
                    dist[adjnode] = time+wt;
                    pq.push({dist[adjnode],adjnode});
                    ways[adjnode] = ways[node]%M;
                }
                else if(time+wt==dist[adjnode])
                {
                    ways[adjnode] = (ways[adjnode]+ways[node])%M;
                }
            }
        }
        return ways[n-1]%M;
    }
};