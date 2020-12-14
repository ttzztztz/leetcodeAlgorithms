class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int t = label, layers = 0;
        while (t) {
            layers++;
            t /= 2;
        }
        if (layers % 2 == 0) label = transform(label, layers);
        
        vector<int> ans;
        while (label) {
            ans.push_back(label);
            label /= 2;
        }
        reverse(ans.begin(), ans.end());
        for (int i = 1; i <= ans.size(); i++) {
            int& v = ans[i - 1];
            
            if (i % 2 == 0) v = transform(v, i);
        }
        return ans;
    }
private:
    int transform(int val, int layer) {
        const int start = 1 << (layer - 1);
        const int end = (1 << layer) - 1;
        const int delta = val - start;
        return end - delta;
    }
};
