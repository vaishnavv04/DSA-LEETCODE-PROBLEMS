class Solution {
public:
    bool partition(string sq,int no)
    {
        if(sq=="" && no==0) return 1;
        if(no<0) return 0;
        for(int i=0;i<sq.length();i++)
        {
            string left = sq.substr(0,i+1);
            string right = sq.substr(i+1);
            int lno = stoi(left);
            if(partition(right,no-lno)) return 1;
        }
        return 0;
    }
    int punishmentNumber(int n) {
        int sum = 0;
        for(int i=1;i<=n;i++)
        {
            int sq = i*i;
            if(partition(to_string(sq),i))
            sum+=sq;
        }
        return sum;
    }
};