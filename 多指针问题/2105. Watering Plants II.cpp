class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int ans = 0;
        const int n = plants.size();
        
        int l = 0, r = n - 1, cl = capacityA, cr = capacityB;
        for (; l < r; l++, r--) {
            if (cl >= plants[l]) {
                cl -= plants[l];
            } else {
                cl = capacityA - plants[l];
                ans++;
            }
            
            if (cr >= plants[r]) {
                cr -= plants[r];
            } else {
                cr = capacityB - plants[r];
                ans++;
            }
        }
        
        if (l == r) {
            int& rest = (cl >= cr) ? cl : cr;
            if (rest < plants[l]) ans++;
        }
        
        return ans;
    }
};
