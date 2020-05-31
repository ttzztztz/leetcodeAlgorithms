class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> a1, a2;
        for (int i : target) a1[i]++;
        for (int i : arr) a2[i]++;
        
        return a1 == a2;
    }
};
