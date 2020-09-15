class Solution {
public:
    /**
     * @param words: an array of string
     * @param maxWidth: a integer
     * @return: format the text such that each line has exactly maxWidth characters and is fully
     */
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        const int n = words.size();
        vector<string> answer;
        
        vector<string> cur;
        int curLen = 0;
        
        auto fill = [&](bool last = false) -> void {
            if (cur.empty()) return;

            string nxt;
            if (last) {
                for (const string& s : cur) nxt += s + ' ';
                if (nxt.size() > maxWidth) nxt.pop_back();
                while (nxt.size() < maxWidth) nxt += ' ';
            } else {
                if (cur.size() == 1) {
                    nxt = cur[0];
                    while (nxt.size() < maxWidth) nxt += ' ';
                } else {
                    const int per = (maxWidth - curLen) / (cur.size() - 1);
                    int rest = (maxWidth - curLen) % (cur.size() - 1);
                    
                    for (int j = 0; j < cur.size(); j++) {
                        const string& str = cur[j];
                        for (int k = 0; k < str.size(); k++) nxt += str[k];
                        
                        if (j != cur.size() - 1) {
                            for (int k = 0; k < per; k++) nxt += ' ';
                            if (rest) nxt += ' ', rest--;
                        }
                    }
                }
            }
            
            answer.push_back(nxt);
            curLen = 0;
            cur.clear();
        };
        
        for (int i = 0; i < n; i++) {
            const string& str = words[i];
            const int len = str.size();
            if (curLen + cur.size() + len > maxWidth) {
                fill();
            }
            
            cur.push_back(str);
            curLen += len;
        }
        
        if (!cur.empty()) fill(true);
        return answer;
    }
};