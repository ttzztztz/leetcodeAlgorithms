class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for (int i = 0; i < n.size(); i++) {
            const int d = n[i] - '0';
            ans = max(ans, d);
        }
        return ans;
    }
};
