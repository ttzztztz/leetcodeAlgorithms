class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> all;
        
        for (const string& mail : emails) {
            string local, after;
            int state = 0, ignore = 0;
            
            for (const char ch : mail) {
                if (state == 0) {
                    if (ch == '@') state = 1;
                    else if (ch == '+') ignore = 1;
                    else if (ch == '.') continue;
                    else if (!ignore) local += ch;
                } else if (state == 1) {
                    after += ch;
                }
            }
            
            string cur = local + "@" + after;
            all.insert(cur);
        }
        
        return all.size();
    }
};