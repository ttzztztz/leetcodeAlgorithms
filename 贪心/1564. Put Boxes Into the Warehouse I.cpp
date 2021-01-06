class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        if (warehouse.empty()) return 0;
        
        sort(boxes.begin(), boxes.end());
        for (size_t i = 1; i < warehouse.size(); i++) {
            warehouse[i] = min(warehouse[i], warehouse[i - 1]);
        }
        
        int ans = 0;
        const int n = warehouse.size();
        for (int i = n - 1, j = 0; i >= 0 && j < boxes.size(); i--) {
            if (boxes[j] <= warehouse[i]) {
                j++;
                ans++;
            }
        }
        return ans;
    }
};
