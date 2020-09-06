class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int answer = 999999;
        const int N = A.size();
        vector<long long> sum(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            sum[i] = sum[i - 1] + A[i - 1];
        }
        
        vector<int> stack;
        for (int i = 0; i <= N; i++) {
            while (!stack.empty() && sum[stack.back()] >= sum[i]) stack.pop_back();
            
            if (stack.size()) {
                int left = 0, right = stack.size() - 1;
                while (left <= right) {
                    const int middle = (left + right) >> 1;
                    if (sum[i] - sum[stack[middle]] >= K) {
                        left = middle + 1;
                    } else {
                        right = middle - 1;
                    }
                }
                
                left--;
                if (left >= 0 && sum[i] - sum[stack[left]] >= K) answer = min(answer, i - stack[left]);
            }
            
            stack.push_back(i);
        }
        
        if (answer >= 999999) {
            return -1;
        }
        return answer;
    }
};
