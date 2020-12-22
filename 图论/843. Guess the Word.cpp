/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        const int n = wordlist.size();
        vector<vector<vector<int>>> edges(n, vector<vector<int>>(7, vector<int>{}));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                const int same_word = SameWord(wordlist[i], wordlist[j]);
                edges[i][same_word].push_back(j);
                edges[j][same_word].push_back(i);
            }
        }

        vector<int> candidate;
        for (int i = 0; i < n; i++) candidate.push_back(i);

        while (!candidate.empty()) {
            const int idx = rand() % candidate.size();
            const int t = candidate[idx];
            candidate.erase(candidate.begin() + idx);
            
            const int match = master.guess(wordlist[t]);
            if (match == 6) return;

            candidate = Intersection(candidate, edges[t][match]);
        }
    }
private:
    int SameWord(const string& lhs, const string& rhs) {
        int ans = 0;
        for (int i = 0; i < lhs.size(); i++) {
            if (lhs[i] == rhs[i]) ans++;
        }
        return ans;
    }
    
    vector<int> Intersection(const vector<int>& s1, const vector<int>& s2) {
        unordered_set<int> s1_set(s1.begin(), s1.end());
        vector<int> ans;
        for (int i = 0; i < s2.size(); i++) {
            if (s1_set.count(s2[i])) ans.push_back(s2[i]);
        }
        return ans;
    }
};
