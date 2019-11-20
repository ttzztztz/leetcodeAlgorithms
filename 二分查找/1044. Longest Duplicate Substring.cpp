class Solution {
public:
    int N;
    long long MOD;
    long long fastPow(long long a, int b) {
        unsigned long long answer = 1;
        while (b) {
            if (b & 1) {
                answer = (answer * a) % MOD;
            }
            a = (a * a) % MOD;
            b >>= 1;
        }
        return answer;
    }

    int solve(const string& S, const int L) {
        unordered_set<long long> hashSet;
        long long hash = 0;
        int left = 0, right = 0;
        while (right < L) {
            hash = (hash + (S[right] - 'a') * fastPow(26, L - right - 1) % MOD) % MOD;
            right++;
        }
        right--;

        const long long a__L = fastPow(26, L - 1);
        hashSet.insert(hash);

        while (right < N) {
            hash = (hash - ((S[left] - 'a') * a__L % MOD) + MOD) % MOD;
            left++, right++;
            hash = hash * 26 % MOD;
            hash = (hash + (S[right] - 'a')) % MOD;
            if (hashSet.count(hash)) {
                return left;
            }
            hashSet.insert(hash);
        }
        return -1;
    }
    string longestDupSubstring(string S) {
        N = S.size(), MOD = 1ll << 32;
        int left = 1, right = N - 1;

        while (left <= right) {
            const int middle = (left + right) >> 1;
            if (solve(S, middle) != -1) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        const int find = left - 1;
        if (find <= 0) {
            return "";
        }
        const int solveResult = solve(S, find);
        return solveResult < 1 ? "" : S.substr(solveResult, find);
    }
};