class Solution {
public:
    string clearDigits(string s) {
        string str ="";
        int d = 0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]>='0' && s[i]<='9')
            d++;
            else
            {
                if(d>0)
                d--;
                else
                str+=s[i];
            }
        }
        reverse(str.begin(),str.end());
        return str;
    }
};