class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.empty()) return 0;
        const int n = arr.size();
        if (n == 1) return 1;
        if (n == 2) {
            if (arr[0] == arr[1]) return 1;
            else return 2;
        }
        
        int ans = 0, cur = 1;
        for (int i = 2; i < n; i++) {
            const int t = cmp(arr[i - 1], arr[i]), r = cmp(arr[i - 2], arr[i - 1]);
            if (t * r == -1) {
                cur++;
                ans = max(ans, cur + 1);
            } else {
                cur = 1;
                
                if (t * r == 0) ans = max(ans, 1);
                else ans = max(ans, 2); // t * r == 1
            }
        }
        
        return ans;
    }
private:
    int cmp(int lhs, int rhs) {
        if (lhs < rhs) return -1;
        else if (lhs > rhs) return 1;
        else return 0; // lhs == rhs
    }
};
