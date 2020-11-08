class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> v(105, 0);
        
        v[1] = 1;
        for (int i = 1; i <= 100; i++) {
            if (2 * i < v.size()) v[2 * i] = v[i];
            if (2 * i + 1 < v.size()) v[2 * i + 1] = v[i] + v[i + 1];
        }
        
        return *max_element(v.begin(), v.begin() + n + 1);
    }
};
