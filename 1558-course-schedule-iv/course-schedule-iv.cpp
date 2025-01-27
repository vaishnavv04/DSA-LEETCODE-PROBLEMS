class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& a, vector<vector<int>>& b) {
        unordered_map<int,unordered_set<int>>m;
        for(int i=0;i<a.size();i++)
        m[a[i][1]].insert(a[i][0]);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(m[j].find(i)!=m[j].end())
                m[j].insert(m[i].begin(),m[i].end());
            }
        }
        vector<bool>v;
        for(int i=0;i<b.size();i++)
        {
            unordered_set<int>t=m[b[i][1]];
            if(t.find(b[i][0])!=t.end())
            v.push_back(true);
            else
            v.push_back(false);

        }
        return v;
    }
};