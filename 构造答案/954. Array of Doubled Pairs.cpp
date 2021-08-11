class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> appear;
        for (int i : arr) appear[i]++;
        if (appear[0] % 2 == 1) return false;
        
        vector<int> pos, neg;
        for (int i : arr) {
            if (i > 0) pos.push_back(i);
            else if (i < 0) neg.push_back(i);
        }
        sort(pos.begin(), pos.end());
        sort(neg.rbegin(), neg.rend());
        
        for (int i : pos) {
            if (appear[i] == 0) continue;
            if (appear[i] > appear[i * 2]) return false;
            appear[i * 2] -= appear[i];
            appear[i] = 0;
        }
        
        for (int i : neg) {
            if (appear[i] == 0) continue;
            if (appear[i] > appear[i * 2]) return false;
            appear[i * 2] -= appear[i];
            appear[i] = 0;
        }
        return true;
    }
};
