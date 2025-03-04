class Solution {
public:
    bool allpos(int p,int n)
    {
        if(n==0) return 1;
        if(pow(3,p)>n) return 0;
        bool take = allpos(p+1,n-pow(3,p));
        bool nottake = allpos(p+1,n);
        return take || nottake ;
    }
    bool checkPowersOfThree(int n) {
        while(n)
        {
            if(n%3==2) return 0;
            n/=3;
        }
        return 1;
    }
};