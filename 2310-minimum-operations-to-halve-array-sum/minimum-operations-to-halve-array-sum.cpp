class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = 0;
        priority_queue<double> pq;
        for(auto it:nums)
        {
            pq.push(it);
            sum+=it;
        }
        double thres = sum/2;
        int ops = 0;
        while(sum>thres)
        {
            double x = pq.top(); pq.pop();
            double y = x/2;
            sum-=y;
            pq.push(y);
            ops++;
            cout<<x;
        }
        return ops;
    }
};