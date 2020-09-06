class Solution {
public:
    /**
     * @param L: Given n pieces of wood with length L[i]
     * @param k: An integer
     * @return: The maximum length of the small pieces
     */
    int woodCut(vector<int> &L, int k) {
        // write your code here
        long long l = 1, r = accumulate(L.begin(), L.end(), 0l);
        while (l <= r) {
            const long long mid = (l + r) >> 1;
            if (solve(L, mid) < k) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
private:
    int solve(const vector<int>& L, long long len) {
        long long answer = 0;
        for (int i : L) answer += i / len;
        return answer;
    }
};
