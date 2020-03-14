class Solution {
public:
    /**
     * @param arr: the line 
     * @param k: Alex place
     * @return: the time when Alex requires to buy all passes
     */
    int buyPasses(vector<int> &arr, int k) {
        int answer = 0;
        const int N = arr.size();
        for (int i = 0; i < N; i++) {
            if (i <= k) answer += min(arr[i], arr[k]);
            else answer += min(arr[i], arr[k] - 1);
        }
        return answer;
    }
};
