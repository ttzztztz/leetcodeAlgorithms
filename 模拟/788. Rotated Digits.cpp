class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += is_good_digits(to_string(i));
        }
        return ans;
    }
private:
    bool is_good_digits(const string& s) {
        unordered_map<char, char> mapping {
            {'0', '0'},
            {'1', '1'},
            {'2', '5'},
            {'5', '2'},
            {'6', '9'},
            {'8', '8'},
            {'9', '6'},
        };

        string new_number;
        for (int i = 0; i < s.size(); i++) {
            if (!mapping.count(s[i])) return false;
            new_number.push_back(mapping[s[i]]);
        }
        return s != new_number;
    }
};