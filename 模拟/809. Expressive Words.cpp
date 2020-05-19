class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        vector<PCI> S_translated = translate(S);
        int answer = 0;
        for (const string& str : words) {
            if (cmp(translate(str), S_translated)) {
                // cout << str << endl;
                answer++;
            }
        }
        return answer;
    }
private:
    typedef pair<char, int> PCI;
    bool cmp(const vector<PCI>& str, const vector<PCI>& S) {
        if (str.size() != S.size()) return false;
        
        for (int i = 0; i < S.size(); i++) {
            const auto& p1 = str[i], p2 = S[i];
            if (p1.first != p2.first) return false;
            
            if (p1.second > p2.second || !(p1.second == p2.second || p2.second >= 3)) return false;
        }
        return true;
    }
    vector<PCI> translate(const string& s) {
        vector<PCI> answer;
        for (int i = 0; i < s.size(); i++) {
            if (i == 0 || s[i] != s[i - 1]) answer.emplace_back(s[i], 1);
            else answer[answer.size() - 1].second++;
        }
        return answer;
    }
};
