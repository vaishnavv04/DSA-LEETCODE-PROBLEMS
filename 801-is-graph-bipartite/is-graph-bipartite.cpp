class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int v,int c,vector<int>&color)
    {
        color[v] = c;
        for(auto it:graph[v])
        {
            if(color[it]==-1)
            {
                int nc ;
                if(c==1) nc = 0;
                else nc = 1;
                if(!dfs(graph,it,nc,color))
                return 0;
            }
            else
            {
                if(color[it]==c)
                return 0;
            }
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(!dfs(graph,i,0,color))
                return 0;
            }
        }
        return 1;
    }
};