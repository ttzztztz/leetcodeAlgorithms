class Solution {
public:
    string addStrings(string num1, string num2) {
        const int N = num1.size(), M = num2.size();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        string answer(max(N, M), 0);
        for (int i = 0, extra = 0; i < max(N, M); i++) {
            const int a = i < num1.size() ? (num1[i] - '0') : 0;
            const int b = i < num2.size() ? (num2[i] - '0') : 0;
            
            int x = a + b + extra;
            if (x >= 10) extra = 1, x -= 10;
            else extra = 0;
            
            answer[i] = x + '0';
            if (i == max(N, M) - 1 && extra) answer.push_back('1');
        }
        
        for (int i = answer.size() - 1; i > 0; i--) {
            if (answer[i] == '0') answer.pop_back();
            else break;
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};