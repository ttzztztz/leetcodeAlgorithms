class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        const int MOD = 1e9 + 7;
        vector<long long> appear(105, 0);
        for (int a : A) {
            appear[a]++;
        }

        long long answer = 0;
        // x == y == z
        if (target % 3 == 0) {
            const int x = target / 3;
            if (x >= 0 && x <= 100) {
                answer += appear[x] * (appear[x] - 1) * (appear[x] - 2) / 6;
                answer %= MOD;
            }
        }

        // x == y, y != z
        for (int x = 0; x <= 100; x++) {
            const int z = target - x * 2;
            if (z <= 100 && z > x) {
                answer += appear[x] * (appear[x] - 1) / 2 * appear[z];
                answer %= MOD;
            }
        }

        // x != y, y == z
        for (int z = 0; z <= 100; z++) {
            const int x = target - z * 2;
            if (x < z && x >= 0) {
                answer += appear[z] * (appear[z] - 1) / 2 * appear[x];
                answer %= MOD;
            }
        }

        // x != y, y != z
        for (int i = 0; i <= 100; i++) {
            for (int j = i + 1; j <= 100; j++) {
                const int k = target - i - j;
                if (k >= 0 && k <= 100 && j < k) {
                    answer += appear[i] * appear[j] * appear[k];
                    answer %= MOD;
                }
            }
        }

        return answer % MOD;
    }
};