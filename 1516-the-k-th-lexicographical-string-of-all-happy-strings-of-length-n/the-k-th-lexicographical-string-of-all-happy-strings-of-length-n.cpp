class Solution {
public:
    vector<string> ans;
    void construct(int n,string &s)
    {
        if(s.size()==n)
        {
            ans.push_back(s);
            return ;
        }
        for(char ch='a';ch<='c';ch++)
        {
            if(s.size()>0)
            {
                if(ch==s.back())
                continue;
                cout<<"helo";
            }
            s+=ch;
            construct(n,s);
            s.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string s = "";
        construct(n,s);
        for(auto it:ans)
        cout<<it<<" ";
        if(k>ans.size())
        return "";
        return ans[k-1];
    }
};