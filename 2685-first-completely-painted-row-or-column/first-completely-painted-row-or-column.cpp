class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size() , n = mat[0].size();
        unordered_map<int,pair<int,int>> mpp;
        unordered_map<int,int> mr , mc;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                mpp[mat[i][j]] = {i,j};
        for(int i=0;i<m*n;i++)
        {
            auto [r , c]  = mpp[arr[i]];
            mr[r]++;
            mc[c]++;
            if(mr[r]==n || mc[c]==m)
            return i;
        }
        return m*n-1;
    }
};