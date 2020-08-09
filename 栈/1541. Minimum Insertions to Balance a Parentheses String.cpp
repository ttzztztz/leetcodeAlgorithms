class Solution {
public:
    int minInsertions(string s) {
        int answer = 0;
        const int N = s.size();
        
        vector<int> stk;
        for (int i = 0; i < N; i++) {
            if (s[i] == '(') stk.push_back(i);
            else { // ')'
                if (i + 1 < N && s[i + 1] == ')') {
                    i++;
                    if (stk.empty()) answer += 1;
                    else {
                        stk.pop_back();
                    }
                } else {
                    if (stk.empty()) answer += 2;
                    else {
                        stk.pop_back();
                        answer++;
                    }
                }
            }
        }
        
        answer += stk.size() * 2;
        
        return answer;
    }
};
