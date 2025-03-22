class Solution {
public:
    class UnionFind{
    public :
        vector<int> par;
        vector<int> sz;
        UnionFind(int n){
            for(int i=0;i<n;i++)
            {
                par.push_back(i);
                sz.push_back(1);
            }
        }

        int find(int node){
            if(par[node]==node)
            return node;
            return par[node] = find(par[node]);
        }
        void Union(int x,int y)
        {
            int upx = find(x);
            int upy = find(y);
            if(upx==upy) return ;
            if(sz[upx]>sz[upy])
            {
                sz[upx]+=sz[upy];
                par[upy] = upx;
            }
            else
            {
                sz[upy]+=sz[upx];
                par[upx] = upy;
            }
        }
    };
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        UnionFind ds(n);
        unordered_map<int,int> m; // to count edges in each component
        for(auto it:edges)
        {
            ds.Union(it[0],it[1]);
        }
        for(auto it:edges)
        {
            int up = ds.find(it[0]);
            m[up]++;
        }
        int c = 0;
        for(int i=0;i<n;i++)
        {
            if(ds.find(i)==i)
            {
                int nodes = ds.sz[i];
                int req_edges = nodes*(nodes-1)/2;
                if(req_edges==m[i])
                c++;
            }
        }
        return c;
    }
};