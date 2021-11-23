class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        const int n = plants.size();
        
        int ans = 0;
        for (int i = 0; i < n;) {
            int rest = capacity;

            while (i < n && plants[i] <= rest) {
                rest -= plants[i];
                i++;
            }
            
            if (i == n) ans += i;
            else ans += i * 2;
        }
        
        return ans;
    }
};
