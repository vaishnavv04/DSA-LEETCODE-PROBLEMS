class Solution {
public:
    string ans ="";
    void construct(string &s,int n,unordered_set<string>&st)
    {
        if(s.size()==n)
        {
            // cout<<s<<" ";
            if(st.find(s)==st.end())
            ans = s;
            return ;
        }
        s+='0';
        construct(s,n,st);
        s.pop_back();
        s+='1';
        construct(s,n,st);
        s.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string s = "";
        unordered_set<string> st(nums.begin(),nums.end());
        construct(s,n,st);
        return ans;
    }
};