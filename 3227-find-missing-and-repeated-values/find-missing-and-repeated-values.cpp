class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int nsqr = n * n;
        
        long long expected_sum = 1LL * nsqr * (nsqr + 1) / 2;
        long long expected_sum_squares = 1LL * nsqr * (nsqr + 1) * (2 * nsqr + 1) / 6;
        
        long long actual_sum = 0, actual_sum_squares = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                actual_sum += grid[i][j];
                actual_sum_squares += (long long)grid[i][j] * grid[i][j];
            }
        }

        // a - b
        long long diff_sum = actual_sum - expected_sum;

        // a² - b²
        long long diff_sum_squares = actual_sum_squares - expected_sum_squares;
        
        // a + b = (a² - b²) / (a - b)
        long long sum_a_b = diff_sum_squares / diff_sum;
        
        int a = (sum_a_b + diff_sum) / 2;
        int b = (sum_a_b - diff_sum) / 2;
        
        return {a, b};
    }
};