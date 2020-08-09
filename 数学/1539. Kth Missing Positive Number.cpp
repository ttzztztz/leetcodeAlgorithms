class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        const int N = arr.size();
        int lst = 0;
        for (int i = 0; i < N; i++) {
            const int prev = k;
            k -= arr[i] - lst - 1;
            if (k <= 0) {
                return lst + prev;
            }
            lst = arr[i];
        }
        return lst + k;
    }
};
