class Solution {
public:
    int largestInteger(int num) {
        string t = to_string(num), ans;
        vector<int> odd, even;
        
        for (auto& c : t) {
            const int d = c - '0';
            if (d % 2 == 1) odd.push_back(d);
            else even.push_back(d);
        }
        
        sort(odd.begin(), odd.end(), [&](const auto& lhs, const auto& rhs) -> bool {
            return lhs > rhs;
        });
        sort(even.begin(), even.end(), [&](const auto& lhs, const auto& rhs) -> bool {
            return lhs > rhs;
        });
        
        for (int i = 0, o = 0, e = 0; i < t.size(); i++) {
            const int d = t[i] - '0';
            
            if (d % 2 == 1) ans.push_back('0' + odd[o++]);
            else ans.push_back('0' + even[e++]);
        }
        
        return stoi(ans);
    }
};
