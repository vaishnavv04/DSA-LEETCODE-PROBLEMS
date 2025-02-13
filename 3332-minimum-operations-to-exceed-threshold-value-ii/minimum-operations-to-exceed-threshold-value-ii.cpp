class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(auto it:nums)
        pq.push(it);
        int ans = 0;
        while(pq.size()>1 && pq.top()<k)
        {
            long long a = pq.top(); pq.pop();
            if(pq.empty())
            break;
            long long b = pq.top();pq.pop();
            pq.push(a*2+b);
            ans++;
        }
        return ans;
    }
};