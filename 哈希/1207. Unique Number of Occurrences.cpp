class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> a;
        unordered_set<int> visited;
        for (int i : arr) a[i]++;
        for (auto& [k, v] : a) {
            if (visited.count(v)) return false;
            else visited.insert(v);
        }
        return true;
    }
};