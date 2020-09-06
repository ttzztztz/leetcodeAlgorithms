class Solution {
public:
    int countTriplets(vector<int>& arr) {
        const int N = arr.size();
        vector<int> f(N + 1);
        for (int i = 1; i <= N; i++) f[i] = f[i - 1] ^ arr[i - 1];
        
        auto prefix = [&](int i, int j) -> int {
            return f[j + 1] ^ f[i];
        };
        
        int answer = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                for (int k = j; k < N; k++) {
                    const int a = prefix(i, j - 1), b = prefix(j, k);
                    if (a == b) answer++;
                }
            }
        }
        return answer;
    }
};
