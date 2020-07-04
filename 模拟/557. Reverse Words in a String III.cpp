class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) return "";
        string answer;
        stringstream ss(s);
        string tmp;
        while (ss >> tmp) {
            reverse(tmp.begin(), tmp.end());
            answer += tmp + " ";
        }
        answer.pop_back();
        return answer;
    }
};