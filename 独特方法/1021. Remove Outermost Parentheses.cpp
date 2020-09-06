class Solution {
public:
    string removeOuterParentheses(string S) {
        const int N = S.size();
        string answer;
        int balance = 0;
        
        for (int i = 0; i < N; i++) {
            const char ch = S[i];
            
            if (ch == '(') {
                if (balance >= 1) answer += ch;
                balance++;
            } else {
                balance--;
                if (balance >= 1) answer += ch;
            }
        }
        return answer;
    }
};