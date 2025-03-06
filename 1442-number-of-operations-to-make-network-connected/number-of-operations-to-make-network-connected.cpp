class Solution {
public:
    int findpar(int node,vector<int>&par)
    {
        if(node==par[node])
        return node;
        return par[node] = findpar(par[node],par);
    }
    void unionbysize(int x,int y,vector<int>&par,vector<int>&size)
    {
            int upx = findpar(x,par) , upy = findpar(y,par);
            if(upx==upy)
            return ;
            if(size[upx]>=size[upy])
            {
                par[upy] = upx;
                size[upx]+=size[upy];
            }
            else
            {
                par[upx] = upy;
                size[upy]+=size[upx];
            }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
        return -1;
        vector<int> par(n),size(n,1);
        for(int i=0;i<n;i++)
        par[i] = i;
        for(auto connection:connections)
        {
            unionbysize(connection[0],connection[1],par,size);
        }
        unordered_set<int> s;
        for(int i=0;i<n;i++)
        {
            findpar(i,par);
            s.insert(par[i]);
        }
        return s.size()-1;
    }
};