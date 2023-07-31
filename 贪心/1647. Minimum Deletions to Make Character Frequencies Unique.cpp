class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> freq_map;
        for (const char& ch : s) freq_map[ch]++;
        vector<int> freq, new_freq;
        for (const auto& [_, v] : freq_map) freq.push_back(v);
        sort(freq.begin(), freq.end(), [](const int& lhs, const int& rhs) -> bool {
            return lhs > rhs;
        });
        new_freq = freq;
        const int n = freq.size();
        for (int i = 1; i < n; i++) {
            if (new_freq[i] < new_freq[i - 1]) continue;

            new_freq[i] = max(0, new_freq[i - 1] - 1);
        }
        int ans = 0;
        for (int i = 1; i < n; i++) ans += freq[i] - new_freq[i];
        return ans;
    }
};