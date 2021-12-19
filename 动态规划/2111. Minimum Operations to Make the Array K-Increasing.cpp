class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int ans = 0;
        for (int i = 0; i < k; i++) {
            vector<int> t;
            for (int j = i; j < arr.size(); j += k) t.push_back(arr[j]);
            ans += t.size() - lis(t);
        }
        return ans;
    }
private:
    int lis(const vector<int>& cur) {
        vector<int> stk;
        for (int t : cur) {
            if (stk.empty() || stk.back() <= t) {
                stk.push_back(t);
            } else {
                auto it = upper_bound(stk.begin(), stk.end(), t);
                *it = t;
            }
        }
        return stk.size();
    }
};
