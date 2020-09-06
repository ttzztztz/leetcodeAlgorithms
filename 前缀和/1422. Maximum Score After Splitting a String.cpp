class Solution {
public:
    int maxScore(string s) {
        int answer = 0;
        int cnt0 = 0, cnt1 = 0;
        vector<int> prefix(s.size() + 5, 0), suffix(s.size() + 5, 0);
        for (int i = 1; i <= s.size(); i++) {
            if (s[i - 1] == '0') prefix[i] = prefix[i - 1] + 1;
            else prefix[i] = prefix[i - 1];
        }
        for (int i = s.size(); i >= 1; i--) {
            if (s[i - 1] == '1') suffix[i] = suffix[i + 1] + 1;
            else suffix[i] = suffix[i + 1];
        }
        
        for (int i = 1; i < s.size(); i++) {
            answer = max(answer, prefix[i] + suffix[i + 1]);
        }
        return answer;
    }
};
