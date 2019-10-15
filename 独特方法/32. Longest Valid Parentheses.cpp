class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, answer = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                left++;
            } else if (s[i] == ')') {
                right++;
            }

            if (left == right) {
                answer = std::max(answer, left + right);
            } else if (right > left) {
                left = right = 0;
            }
        }

        left = 0, right = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else if (s[i] == ')') {
                right++;
            }

            if (left == right) {
                answer = std::max(answer, left + right);
            } else if (left > right) {
                left = right = 0;
            }
        }
        return answer;
    }
};