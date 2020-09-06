class Solution {
public:
    bool checkValidString(string s) {
        vector<int> left, star;
        const int N = s.size();
        
        for (int i = 0; i < N; i++) {
            if (s[i] == '(') left.push_back(i);
            else if (s[i] == '*') star.push_back(i);
            else if (s[i] == ')') {
                if (!left.empty()) left.pop_back();
                else if (!star.empty()) star.pop_back();
                else return false;
            }
        }
        
        if (left.size() > star.size()) return false;
        while (!left.empty()) {
            if (left.back() < star.back()) {
                left.pop_back();
                star.pop_back();
            } else {
                return false;
            }
        }
        return true;
    }
};
