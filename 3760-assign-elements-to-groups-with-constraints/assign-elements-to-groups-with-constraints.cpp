class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int n=groups.size();
        int m=elements.size();
        int maxi=-1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,groups[i]);
        }
        unordered_map<int,int>mp;
        for(int i=0;i<m;i++){
            if(mp.count(elements[i])==0){
                int x=elements[i];
                int y=x;
                int cnt=2;
                while(x<=maxi){
                    if(mp.count(x)==0){
                        mp[x]=i;
                    }
                    x=y*cnt;
                    cnt++;
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(mp.count(groups[i])!=0){
                ans.push_back(mp[groups[i]]);
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};