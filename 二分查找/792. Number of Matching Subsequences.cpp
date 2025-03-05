class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> idx;
        for (int i = 0; i < s.size(); i++) idx[s[i]].push_back(i);
        int ans = 0;
        for (const string& word : words) {
            if (judge(idx, word)) ans++;
        }
        return ans;
    }
private:
    bool judge(unordered_map<char, vector<int>>& idx, const string& word) {
        const int n = word.size();
        int ptr_s = 0;
        for (int ptr_w = 0; ptr_w < n; ptr_w++) {
            const char ch = word[ptr_w];
            if (!idx.count(ch)) {
                return false;
            }
            const vector<int>& v = idx[ch];
            auto it = lower_bound(v.begin(), v.end(), ptr_s);
            if (it == v.end()) {
                return false;
            }
            ptr_s = *it + 1;
        }
        return true;
    }
};