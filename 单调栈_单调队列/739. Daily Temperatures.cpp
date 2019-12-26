class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> answer;
        const int N = T.size();
        answer.resize(N);

        vector<int> stack;
        for (int i = N - 1; i >= 0; i--) {
            while (stack.size() > 0 && T[stack.back()] <= T[i]) {
                stack.pop_back();
            }

            if (stack.size() == 0) {
                answer[i] = 0;
            } else {
                answer[i] = stack.back() - i;
            }
            stack.push_back(i);
        }
        return answer;
    }
};