class Solution {
public:
    string reformat(string s) {
        vector<char> s1, s2;
        for (const char ch : s) {
            if (ch >= '0' && ch <= '9') {
                s1.push_back(ch);
            } else {
                s2.push_back(ch);
            }
        }
        
        string answer;
        int cnt = 0;
        if (s1.size() > s2.size()) {
            answer.push_back(s1.back());
            s1.pop_back();
            if (s1.size() != s2.size()) return "";
        } else if (s1.size() < s2.size()) {
            answer.push_back(s2.back());
            s2.pop_back();
            if (s1.size() != s2.size()) return "";
            cnt = 1;
        }
        
        while (!s1.empty() || !s2.empty()) {
            if (cnt & 1) {
                answer.push_back(s1.back());
                s1.pop_back();
            } else {
                answer.push_back(s2.back());
                s2.pop_back();
            }
            cnt ^= 1;
        }
        
        return answer;
    }
};
