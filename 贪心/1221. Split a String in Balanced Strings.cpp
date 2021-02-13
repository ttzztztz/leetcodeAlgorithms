class Solution {
public:
    int balancedStringSplit(string s) {
        const int N = s.size();
        int answer = 0, balance = 0;
        for (int i = 0; i < N; i++) {
            if (s[i] == 'L') balance++;
            else balance--;
            
            if (balance == 0) answer++;
        }
        return answer;
    }
};