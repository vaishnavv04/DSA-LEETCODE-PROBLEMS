class Solution {
public:
    bool doesValidArrayExist(vector<int>& v) {
        int n = v.size();
        if(n==1)
        {
            return v[0]==0 ? 1 : 0;
        }
        int first = 1;
        int next ;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                if(v[i]==1)
                next = 0;
                else 
                next = 1;
            }
            else
            {
                if(next==0)
                {
                    if(v[i]==1)
                    next = 1;
                    else 
                    next = 0;
                }
                else
                {
                    if(v[i]==1)
                    next = 0;
                    else 
                    next = 1;
                }
            }
        }
        if(first==next)
        return 1;
        return 0;
    }
};