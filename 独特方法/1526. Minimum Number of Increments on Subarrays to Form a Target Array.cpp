class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int answer = target[0];
        const int N = target.size();
        for (int i = 1; i < N; i++) {
            answer += max(0, target[i] - target[i - 1]);
        }
        return answer;
    }
};
