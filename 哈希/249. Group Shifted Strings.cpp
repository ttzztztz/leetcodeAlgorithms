class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hmap;
        for (const auto& str : strings) {
            const string group_key = group_by_key(str);
            hmap[group_key].push_back(str);
        }

        for (auto& [_, vec] : hmap) {
            ans.push_back(vec);
        }
        return ans;
    }
private:
    string group_by_key(string str) {
        const int delta = str[0] - 'a';

        for (int i = 0; i < str.size(); i++) {
            int cur = str[i] - 'a';
            cur = (cur - delta + 26) % 26;
            str[i] = 'a' + cur;
        }
        return str;
    }
};