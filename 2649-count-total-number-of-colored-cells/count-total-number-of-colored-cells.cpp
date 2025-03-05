class Solution {
public:
    long long coloredCells(int n) {
        long long res = n-1;
        res = 1+4*res*(res+1)/2;
        return res;
    }
};