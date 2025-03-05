class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> appear_hashmap;
        for (const int& i : nums) appear_hashmap[i]++;

        vector<pair<int, int>> freq;
        for (auto [val, cnt] : appear_hashmap) freq.emplace_back(val, cnt);
        const int m = freq.size();

        quick_select(freq, 0, m - 1, m - k);

        vector<int> ans;
        for (int i = m - k; i < m; i++) ans.push_back(freq[i].first);
        return ans;
    }
private:
    void quick_select(vector<pair<int, int>>& freq, int i, int j, int k) {
        if (i >= j) return;

        const int pivot = freq[(i + j) / 2].second;
        int l = i, r = j, cur = i;
        while (cur <= r) {
            if (freq[cur].second < pivot) {
                swap(freq[cur], freq[l]);
                cur++, l++;
            } else if (freq[cur].second == pivot) {
                cur++;
            } else { // freq[cur].second > pivot
                swap(freq[cur], freq[r]);
                r--;
            }
        }

        if (l - i > k) quick_select(freq, i, l - 1, k);
        if (k > r - i) quick_select(freq, r + 1, j, k - (r - i) - 1);
    }
};