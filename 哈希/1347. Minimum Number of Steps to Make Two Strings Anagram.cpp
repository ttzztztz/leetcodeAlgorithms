class Solution {
public:
    int minSteps(string s, string t) {
        int answer = 0;
        
        unordered_map<char, int> m1, m2;
        for (const char ch : s) m1[ch]++;
        for (const char ch : t) m2[ch]++;
        
        for (auto& p : m1) {
            answer += abs(p.second - m2[p.first]);
            m2[p.first] = p.second;
        }
        
        for (auto& p : m2) {
            answer += abs(p.second - m1[p.first]);
            m1[p.first] = p.second;
        }
        
        return answer / 2.0;
    }
};
