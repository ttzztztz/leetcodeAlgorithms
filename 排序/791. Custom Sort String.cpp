class Solution {
public:
    string customSortString(string order, string s) {
        const int n = order.size();
        unordered_map<char, int> ord;
        for (int i = 0; i < order.size(); i++) {
            ord[order[i]] = i;
        }

        sort(s.begin(), s.end(), [&](const char $1, const char $2) -> bool {
            const int o1 = ord.count($1) ? ord[$1] : n;
            const int o2 = ord.count($2) ? ord[$2] : n;

            return o1 < o2;
        });
        return s;
    }
};