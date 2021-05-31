class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        if (favoriteCompanies.empty()) return {};
        
        const int n = favoriteCompanies.size();
        vector<unordered_set<string>> hset;
        for (int i = 0; i < n; i++) {
            hset.push_back(unordered_set<string>(favoriteCompanies[i].begin(), favoriteCompanies[i].end()));
        }
        
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (is_subset(favoriteCompanies[i], hset[j])) {
                    flag = false;
                    break;
                }
            }
            
            if (flag) ans.push_back(i);
        }
        return ans;
    }
private:
    bool is_subset(const vector<string>& a, const unordered_set<string>& b) {
        for (const string& x : a) {
            if (!b.count(x)) return false;
        }
        return true;
    }
};