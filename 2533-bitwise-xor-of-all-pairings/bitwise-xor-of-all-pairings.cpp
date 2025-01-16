class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size() ,n2 = nums2.size();
        int xr = 0;
        if(n1&1)
        {
            for(auto it:nums2)
            xr^=it;
        }
        if(n2&1)
        {
            for(auto it:nums1)
            xr^=it;
        }
        return xr;
    }
};