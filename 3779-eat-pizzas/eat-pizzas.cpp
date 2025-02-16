class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        int n = pizzas.size();
        sort(pizzas.begin(),pizzas.end());
        int days = n/4;
        long long  sum = 0;
        int x = n-1;
        for(int i=1;i<=days;i+=2)
        sum+=pizzas[x--];
        for(int i=2;i<=days;i+=2)
        {
            x--;
            sum+=pizzas[x--];
        }
        return sum;
    }
};