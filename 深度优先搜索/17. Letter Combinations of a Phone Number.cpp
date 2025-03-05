class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        unordered_map<char, vector<char>> mapping = {
            { '2', { 'a', 'b', 'c' } },
            { '3', { 'd', 'e', 'f' } },
            { '4', { 'g', 'h', 'i' } },
            { '5', { 'j', 'k', 'l' } },
            { '6', { 'm', 'n', 'o' } },
            { '7', { 'p', 'q', 'r', 's' } },
            { '8', { 't', 'u', 'v' } },
            { '9', { 'w', 'x', 'y', 'z' } }
        };

        deque<string> q = { "" };
        int idx = 0;
        while (!q.empty()) {
            const vector<char>& nxt = mapping[digits[idx]];
            const int cnt = q.size();

            for (int i = 0; i < cnt; i++) {
                const string s = q.front();
                q.pop_front();

                for (const char n : nxt) {
                    q.push_back(s + n);
                }
            }

            idx++;
            if (idx == digits.size()) return vector<string>(q.begin(), q.end());
        }
        return {};
    }
};