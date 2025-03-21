class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,int> m;
        for(auto it:supplies)
        m[it]++;
        int n = recipes.size();
        vector<string> ans;
        int temp = n;
        while(temp--)
        {
            for(int i=0;i<n;i++)
            {
                bool canbemade = 1;
                for(auto it:ingredients[i])
                {
                    if(m.find(it)==m.end())
                    {
                        canbemade = 0;
                        break;
                    }
                }
                if(canbemade)
                {
                    m[recipes[i]]++;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            bool canbemade = 1;
            for(auto it:ingredients[i])
            {
                if(m.find(it)==m.end())
                {
                    canbemade = 0;
                    break;
                }
            }
            if(canbemade)
            {
                ans.push_back(recipes[i]);
            }
        }
        return ans;
    }
};