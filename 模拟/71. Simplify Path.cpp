class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stk;

        string buf;
        for (int i = 0; i < path.size(); i++) {
            if (path[i] != '/') buf += path[i];

            if (path[i] == '/' || i == path.size() - 1) {
                if (buf.empty() || buf == ".") {
                    buf.clear();
                    continue;
                }

                if (buf == "..") {
                    if (!stk.empty()) stk.pop_back();
                } else {
                    stk.push_back(buf);
                }
                buf.clear();
            }
        }

        if (stk.empty()) return "/";
        string ans;
        for (const string& str : stk) ans += "/" + str;
        return ans;
    }
};