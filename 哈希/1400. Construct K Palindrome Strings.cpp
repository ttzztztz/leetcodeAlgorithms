class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char, int> appear;
        const int n = s.size();
        for (const char ch : s) appear[ch]++;
        int odd = 0, even = 0;
        for (auto& [k, v] : appear) {
            if (v % 2 == 1) {
                odd++;
                v--;
            }
            even += v / 2;
        }
        return odd <= k && k <= n;
    }
};