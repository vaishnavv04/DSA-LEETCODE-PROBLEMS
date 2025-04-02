class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    long long diff = static_cast<long long>(nums[i]) - static_cast<long long>(nums[j]);
                    long long product = diff * static_cast<long long>(nums[k]);
                    ans = max(ans, product);
                }
            }
        }
        return ans;
    }
};