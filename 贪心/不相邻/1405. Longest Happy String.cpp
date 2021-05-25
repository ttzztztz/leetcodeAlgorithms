class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        typedef pair<int, char> PIC;
        vector<PIC> v = {
            {a, 'a'}, {b, 'b'}, {c, 'c'}
        };
        
        string ans;
        while (v[0].first || v[1].first || v[2].first) {
            sort(v.rbegin(), v.rend());
            if (ans.empty() || ans.back() != v[0].second) {
                if (v[0].first > 0) {
                    ans += v[0].second;
                    v[0].first--;
                }
                
                if (v[0].first > 0) {
                    ans += v[0].second;
                    v[0].first--;
                }
            } else {
                if (v[1].first > 0) {
                    ans += v[1].second;
                    v[1].first--;
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};