class Solution {
public:
    bool construct(int n, int idx, vector<int>& ans, unordered_set<int>& s) {
        if (idx == ans.size())
            return true;
        if (ans[idx] != 0)
            return construct(n, idx + 1, ans, s);
        for (int i = n; i > 0; i--) {
            if (s.find(i) != s.end())
                continue;
            ans[idx] = i;
            s.insert(i);
            if (i != 1) {
                if (idx + i < ans.size() && ans[idx + i] == 0) {
                    ans[idx + i] = i;
                    if (construct(n, idx + 1, ans, s))
                        return true;
                    ans[idx + i] = 0;
                }
            } else {
                if (construct(n, idx + 1, ans, s))
                    return true;
            }
            ans[idx] = 0;
            s.erase(i);
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        unordered_set<int> s;
        vector<int> ans(2 * n - 1);
        construct(n, 0, ans, s);
        return ans;
    }
};
