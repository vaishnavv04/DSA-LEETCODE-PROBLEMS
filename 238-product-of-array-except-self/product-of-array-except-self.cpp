class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {

        int pro = 1;
        int zeros = 0;
        for(auto it:arr)
        {
            if(it!=0)
            pro*=it;
            else
            zeros++;
        }
        vector<int> v;
        for(auto it:arr)
        {
            if(zeros)
            {
                if(it!=0)
                v.push_back(0);
                else
                {
                    if(zeros==1)
                    v.push_back(pro);
                    else
                    v.push_back(0);
                }
            }
            else
            {
                v.push_back(pro/it);
            }
        }
        return v;
    }
};