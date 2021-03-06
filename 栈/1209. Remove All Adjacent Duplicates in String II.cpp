class Solution {
public:
    string removeDuplicates(string s, int k) {
        string ans;
        vector<int> repeat;
        
        for (int i = 0; i < s.size(); i++) {
            const char ch = s[i];
            if (ans.empty() || ans.back() != ch) {
                ans.push_back(ch);
                repeat.push_back(1);
            } else { // ans.back() == ch
                if (repeat.back() + 1 == k) {
                    for (int j = 0; j < k - 1; j++) {
                        ans.pop_back();
                        repeat.pop_back();
                    }
                } else {
                    ans.push_back(ch);
                    repeat.push_back(repeat.back() + 1);
                }
            }
        }
        return ans;
    }
};
