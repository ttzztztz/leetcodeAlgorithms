class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int, int>> s;
        const int n = nums.size();
        for (int i = 0; i < n; i++) s.emplace_back(nums[i], i);
        sort(s.begin(), s.end());
        vector<int> indices;
        auto put_group = [&]() -> void {
            vector<int> new_values;
            for (auto& i : indices) new_values.push_back(nums[i]);
            sort(indices.begin(), indices.end());
            const int m = indices.size();
            for (int i = 0; i < m; i++) {
                const int idx = indices[i];
                const int new_value = new_values[i];
                nums[idx] = new_value;
            }
            indices.clear();
        };

        for (int i = 0, begin = -1; i < n; i++) {
            const auto [t, j] = s[i];
            if (begin == -1 || t - s[i - 1].first > limit) {
                put_group();
                begin = i;
                indices = { j };
            } else {
                indices.push_back(j);
            }
        }
        put_group();
        return nums;
    }
};