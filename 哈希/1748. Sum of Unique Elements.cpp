class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> a;
        for (int i : nums) a[i]++;
        for (auto [k, v] : a) {
            if (v == 1) ans += k;
        }
        return ans;
    }
};
