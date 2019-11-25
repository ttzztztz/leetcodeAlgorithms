class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        const int N = A.size(), MOD = 1e9+7;

        unordered_map<int, int> map;
        long long answer = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                answer = (answer + map[A[i] + A[j]]) % MOD;
            }
            map[target - A[i]]++;
        }
        return answer % MOD;
    }
};