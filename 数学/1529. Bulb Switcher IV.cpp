class Solution {
public:
    int minFlips(string target) {
        const int N = target.size();
        int answer = 0;
        for (int i = 0; i < N; i++) {
            if ((target[i] == '1' && answer % 2 == 0) || (target[i] == '0' && answer % 2 == 1)) answer++;
        }
        return answer;
    }
};
