class Solution {
public:
    vector<int> lexicalOrder(int n) {
        if (n == 0) return {};

        vector<int> ans;
        int cur = 1;
        for (int i = 0; i < n; i++) {
            ans.push_back(cur);
            cur = next(cur, n);
        }
        return ans;
    }
private:
    int next(int cur, int n) {
        if (cur * 10 <= n) {
            cur = cur * 10;
            return cur;
        }

        while (cur + 1 > n || cur % 10 == 9) {
            cur = cur / 10;
        }
        return cur + 1;
    }
};