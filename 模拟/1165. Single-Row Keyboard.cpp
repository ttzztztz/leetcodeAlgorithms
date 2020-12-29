class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> idx;
        for (int i = 0; i < keyboard.size(); i++) idx[keyboard[i]] = i;
        
        int cur = 0, ans = 0;
        for (const char ch : word) {
            const int pos = idx[ch];
            ans += abs(pos - cur);
            cur = pos;
        }
        return ans;
    }
};
