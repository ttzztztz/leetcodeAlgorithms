class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        vector<int> answer;
        const int N = favoriteCompanies.size();
        vector<unordered_set<string>> f(N);
        for (int i = 0; i < N; i++) f[i] = unordered_set<string>(favoriteCompanies[i].begin(), favoriteCompanies[i].end());
        
        for (int i = 0; i < N; i++) {
            bool ok = false;
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                if (isSubset(favoriteCompanies[i], f[j])) {
                    ok = true;
                    break;
                }
            }
            
            if (!ok) answer.push_back(i);
        }
        return answer;
    }
private:
    bool isSubset(vector<string>& sub, unordered_set<string>& all) {
        for (const auto& s : sub) {
            if (!all.count(s)) return false;
        }
        return true;
    }
};
