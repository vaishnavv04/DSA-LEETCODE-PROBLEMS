class Solution {
public:
    bool dfs(vector<vector<int>> &adj,int i,vector<int>&vis,vector<int>&pathvis,stack<int>&st)
    {
        vis[i] = 1;
        pathvis[i] = 1;
        for(auto it:adj[i])
        {
            if(!vis[it])
            {
                if(dfs(adj,it,vis,pathvis,st))
                return 1;
            }
            if(pathvis[it])
            return 1;
        }
        st.push(i);
        pathvis[i] = 0;
        return 0;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for(auto it:pre)
        adj[it[1]].push_back(it[0]);
        vector<int> vis(n),pathvis(n);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(dfs(adj,i,vis,pathvis,st))
                return {};
            }
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};