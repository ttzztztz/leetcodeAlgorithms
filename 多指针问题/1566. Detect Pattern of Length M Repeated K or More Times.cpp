class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        const int n = arr.size();
        
        for (int l = 0, r = m - 1; r < n; l++, r++) {
            string $1 = substr(arr, l, r);
            int cnt = 1;
            for (int l2 = r + 1, r2 = l2 + m - 1; r2 < n; l2 += m, r2 += m) {
                string $2 = substr(arr, l2, r2);
                
                if ($1 != $2) {
                    cnt = -1;
                    break;
                } else {
                    cnt++;
                    if (cnt >= k) return true;
                }
            }
        }
        
        return false;
    }
private:
    string substr(const vector<int>& v, int l, int r) {
        string ans;
        for (int i = l; i <= r; i++) ans += to_string(v[i]) + ",";
        return ans;
    }
};