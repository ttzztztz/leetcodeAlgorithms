class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {
        int l = *min_element(sweetness.begin(), sweetness.end()), r = accumulate(sweetness.begin(), sweetness.end(), 0);
        while (l <= r) {
            const int mid = (l + r) / 2;
            if (Solve(sweetness, mid) >= K + 1) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l - 1;
    }
private:
    int Solve(const vector<int>& sweetness, int min_chunk) {
        int ans = 0, sum = 0;
        for (int i = 0; i < sweetness.size(); i++) {
            sum += sweetness[i];
            if (sum >= min_chunk) {
                sum = 0;
                ans++;
            }
        }
        return ans;
    }
};
