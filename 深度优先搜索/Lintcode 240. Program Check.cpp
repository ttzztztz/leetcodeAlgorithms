class Solution {
public:
    /**
     * @param commands: the commands of this program.
     * @return: return is the program may be in endless loop.
     */
    bool check(vector<string> &commands) {
        // write your code here.
        vector<vector<string>> parsed;
        for (int i = 0; i < commands.size(); i++) {
            const string& c = commands[i];
            stringstream ss(c);
            string cmd;
            ss >> cmd;
            if (cmd == "label") {
                string seg;
                ss >> seg;
                label[seg] = i;
            }
            
            vector<string> tmp = {cmd};
            string buffer;
            while (ss >> buffer) {
                tmp.push_back(buffer);
            }
            parsed.push_back(tmp);
        }
        
        visited = vector<bool>(commands.size(), false);
        return exec(parsed, 0);
    }
private:
    unordered_map<string, int> label;
    vector<bool> visited;
    bool exec(vector<vector<string>>& commands, int line) {
        if (line == commands.size()) return false;
        if (visited[line]) return true;
        
        visited[line] = true;
        const string& cmd = commands[line][0];
        if (cmd == "label" || cmd == "print") return exec(commands, line + 1);
        else if (cmd == "halt") return false;
        else if (cmd == "goto") return exec(commands, label[commands[line][1]]);
        else if (cmd == "gotorand") {
            const int l1 = label[commands[line][1]], l2 = label[commands[line][2]];
            vector<bool> prevVisited = visited;
            
            return exec(commands, l1) || (visited = prevVisited, exec(commands, l2));
        }

        return false;
    }
};
