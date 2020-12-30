class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        const int n = sentence1.size(), m = sentence2.size();
        if (n != m) return false;
        
        for (const auto& v : similarPairs) {
            similar.insert(hash(v[0], v[1]));
        }
        
        for (int i = 0; i < n; i++) {
            const string& s1 = sentence1[i], s2 = sentence2[i];
            if (s1 != s2 && !similar.count(hash(s1, s2))) return false;
        }
        return true;
    }
private:
    unordered_set<string> similar;
    string hash(string lhs, string rhs) {
        if (lhs > rhs) swap(lhs, rhs);
        return lhs + "," + rhs;
    }
};
