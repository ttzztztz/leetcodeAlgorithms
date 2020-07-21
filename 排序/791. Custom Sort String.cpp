class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char, int> app;
        for (int i = 0; i < S.size(); i++) app[S[i]] = i;
        sort(T.begin(), T.end(), [&](const auto& $1, const auto& $2) -> bool {
            return app[$1] < app[$2];
        });
        return T;
    }
};