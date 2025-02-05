class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size() , c = 0;
        unordered_set<char> st1 , st2;
        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s2[i])
            {
                c++;
                st1.insert(s1[i]);
                st2.insert(s2[i]);
            }
        }
        if(c!=0 && c!=2)
        return 0;
        if(st1==st2)
        return 1;
        return 0;
    }
};