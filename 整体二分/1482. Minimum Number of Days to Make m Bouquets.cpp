class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        this->bloom = bloomDay, this->k = k;
        n = bloom.size();
        
        int l = *min_element(bloom.begin(), bloom.end()), r = *max_element(bloom.begin(), bloom.end());
        while (l <= r) {
            const int mid = (l + r) / 2;
            if (solve(mid) < m) l = mid + 1;
            else r = mid - 1;
        }
        
        if (solve(l) < m) return -1;
        return l;
    }
private:
    int n, k;
    vector<int> bloom;
    int solve(int day) {
        int ans = 0, cur = 0;
        for (int i = 0; i < n; i++) {
            if (bloom[i] <= day) cur++;
            else cur = 0;
            
            if (cur >= k) cur = 0, ans++;
        }
        return ans;
    }
};