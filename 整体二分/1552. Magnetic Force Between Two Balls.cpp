class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 1, r = position.back() - position.front();
        while (l <= r) {
            const int mid = (l + r) >> 1;
            if (solve(position, mid) < m) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
private:
    int solve(const vector<int>& position, int dist) {
        int ans = 1, last = position[0];
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - last >= dist) {
                last = position[i];
                ans++;
            }
        }
        return ans;
    }
};