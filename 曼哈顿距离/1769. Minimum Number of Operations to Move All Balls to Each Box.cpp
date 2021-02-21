class Solution {
public:
    vector<int> minOperations(string boxes) {
        const int n = boxes.size();
        vector<int> ans(n);
        
        vector<int> idx;
        for (int i = 0; i < n; i++) {
            if (boxes[i] == '1') idx.push_back(i);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j : idx) {
                ans[i] += abs(j - i);
            }
        }
        
        return ans;
    }
};
