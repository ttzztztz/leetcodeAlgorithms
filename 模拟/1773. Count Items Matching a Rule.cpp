class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans = 0;
        for (auto& item : items) {
            const string& t = item[0], c = item[1], na = item[2];
            if (ruleKey == "type" && t == ruleValue) ans++;
            if (ruleKey == "color" && c == ruleValue) ans++;
            if (ruleKey == "name" && na == ruleValue) ans++;
        }
        return ans;
    }
};
