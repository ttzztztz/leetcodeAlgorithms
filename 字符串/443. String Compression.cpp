class Solution {
public:
    int compress(vector<char>& chars) {
        typedef pair<char, int> PCI;
        vector<PCI> backup;
        for (int i = 0; i < chars.size(); i++) {
            if (!backup.empty() && backup.back().first == chars[i]) {
                backup.back().second++;
            } else {
                backup.emplace_back(chars[i], 1);
            }
        }
        
        vector<char> new_char;
        for (auto [ch, appear] : backup) {
            if (appear == 1) {
                new_char.push_back(ch);
            } else {
                new_char.push_back(ch);
                string d = to_string(appear);
                for (const char t : d) new_char.push_back(t);
            }
        }
        chars = new_char;
        return chars.size();
    }
};
