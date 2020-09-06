class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> all;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) all.push_back(i);
        }
        
        if (k - 1 >= all.size()) return -1;
        return all[k - 1];
    }
};