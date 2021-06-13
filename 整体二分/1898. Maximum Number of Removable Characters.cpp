class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        const int n = removable.size();
        invalid = vector<int>(s.size() + 1, -1);
        for (int i = 0; i < n; i++) invalid[removable[i]] = i;
        
        int l = 0, r = n;
        while (l <= r) {
            const int mid = (l + r) / 2;
            if (ok(s, p, removable, mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
private:
    vector<int> invalid;
    bool ok(const string& s, const string& p, const vector<int>& removable, int k) {
        const int len_s = s.size(), len_p = p.size();
        int i = 0, j = 0;
        while (i < len_s && j < len_p) {
            while (invalid[i] != -1 && invalid[i] < k) i++;
            
            if (s[i] == p[j]) {
                i++, j++;
            } else {
                i++;
            }
        }
        return j >= len_p;
    }
};