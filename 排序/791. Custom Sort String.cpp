class Solution {
public:
    string customSortString(string order, string str) {
        unordered_map<char, int> ord;
        for (int i = 0; i < order.size(); i++) ord[order[i]] = i;
        sort(str.begin(), str.end(), [&](const auto& lhs, const auto& rhs) -> bool {
            return ord[lhs] < ord[rhs];
        });
        return str;
    }
};