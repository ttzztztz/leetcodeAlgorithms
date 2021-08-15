class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for (auto& p : patterns) {
            if (word.find(p) != string::npos) ans++;
        }
        return ans;
    }
};