class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        const int n = num.size();
        for (int i = 0; i < n; i++) {
            const int d = num[i] - '0';
            if (change[d] > d) {
                return perform(num, i, change);
            }
        }
        return num;
    }
private:
    string perform(string num, int idx, vector<int>& change) {
        const int n = num.size();
        string ans = num;
        for (int i = idx; i < n; i++) {
            const int d = num[i] - '0';
            if (change[d] >= d) {
                ans[i] = '0' + change[d];
            } else {
                break;
            }
        }
        return ans;
    }
};