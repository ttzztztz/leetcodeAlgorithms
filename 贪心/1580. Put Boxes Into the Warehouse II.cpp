class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        if (warehouse.empty()) return 0;
        const int n = boxes.size(), m = warehouse.size();
        sort(boxes.begin(), boxes.end());
        
        vector<int> h1 = warehouse, h2 = warehouse;
        for (int i = 1; i < m; i++) h1[i] = min(h1[i], h1[i - 1]);
        for (int i = m - 2; i >= 0; i--) h2[i] = min(h2[i], h2[i + 1]);
        vector<int> candidate_height;
        for (int i = 0; i < m; i++) candidate_height.push_back(max(h1[i], h2[i]));
        sort(candidate_height.begin(), candidate_height.end());
        
        int ans = 0;
        for (int i = 0, j = 0; i < m && j < n; i++) {
            if (boxes[j] <= candidate_height[i]) {
                j++;
                ans++;
            }
        }
        return ans;
    }
};
