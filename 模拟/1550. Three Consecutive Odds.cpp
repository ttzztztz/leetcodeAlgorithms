class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        const int N = arr.size();
        for (int i = 0; i + 2 < N; i++) {
            if (arr[i] % 2 && arr[i + 1] % 2 && arr[i + 2] % 2) return true;
        }
        return false;
    }
};
