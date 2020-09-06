class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> answer;
        string tmp;
        bool inBlock = false;
        for (const string& line: source) {
            for (int i = 0; i < line.size(); i++) {
                if (i != line.size() - 1) {
                    const auto nxt = line.substr(i, 2);
                    if (!inBlock && nxt == "//") {
                        break;
                    } else if (!inBlock && nxt == "/*") {
                        inBlock = true;
                        i++;
                    } else if (inBlock && nxt == "*/") {
                        inBlock = false;
                        i++;
                    } else {
                        if (!inBlock) tmp.push_back(line[i]);
                    }
                } else if(!inBlock) tmp.push_back(line[i]);
            }
            
            if (!tmp.empty() && !inBlock) {
                answer.push_back(tmp);
                tmp.clear();
            }
        }
        return answer;
    }
};
