class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = 0, answer = 0;
        const int N = machines.size();

        for (int machine : machines) {
            sum += machine;
        }
        if (sum % N) {
            return -1;
        }
        const int avg = sum / N;
        int balance = 0;
        for (int i = 0; i < N; i++) {
            balance += machines[i] - avg;
            answer = std::max(answer, std::max(std::abs(balance), machines[i] - avg));
        }
        return answer;
    }
};