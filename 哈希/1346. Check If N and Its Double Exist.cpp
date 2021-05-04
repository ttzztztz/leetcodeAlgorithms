class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> prev;
        for (int i : arr) {
            if (i % 2 == 0 && prev.count(i / 2)) return true;
            if (prev.count(i * 2)) return true;
            prev.insert(i);
        }
        return false;
    }
};