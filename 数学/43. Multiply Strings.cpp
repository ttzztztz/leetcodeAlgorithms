class Solution {
public:
    string multiply(string num1, string num2) {
        const int N = num1.size(), M = num2.size();
        string answer(N + M + 1, 0);
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                answer[i + j] += (num1[i] - '0') * (num2[j] - '0');
                answer[i + j + 1] += answer[i + j] / 10;
                answer[i + j] %= 10;
            }
        }
        
        for (int i = N + M; i > 0; i--) {
            if (answer[i] == 0) {
                answer.pop_back();
            } else break;
        }
        
        for (int i = 0; i < answer.size(); i++) answer[i] += '0';
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
