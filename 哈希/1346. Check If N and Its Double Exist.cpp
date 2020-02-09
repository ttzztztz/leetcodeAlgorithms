class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        const int N = arr.size();
        int zeroCount = 0;
        unordered_set<int> cnt;
        for (int u : arr) {
            if (u == 0) {
                zeroCount++;
            } else {
                cnt.insert(u);
            }
        }
        
        if (zeroCount >= 2) return true;
        
        for (int u : arr) {
            if (cnt.count(u * 2) && u != 0) return true;
        }
        return false;
    }
};
