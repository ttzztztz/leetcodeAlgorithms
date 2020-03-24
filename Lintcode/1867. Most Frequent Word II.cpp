class Solution {
public:
    /**
     * @param paragraph: a string
     * @return: the most frequent word
     */
    string mostCommonWord(string &paragraph) {
        stringstream ss;
        ss << paragraph;
        string answer, tmp;
        unordered_map<string, int> appear;
        while (ss >> tmp) {
            const int M = tmp.size();
            
            auto it = tmp.begin();
            while (it != tmp.end()) {
                if (*it >= 'A' && *it <= 'Z') {
                    *it = *it - 'A' + 'a';
                } else if (*it == ',' || *it == '!' || *it == '?' || *it == '\'' || *it == ';' || *it == '.') {
                    it = tmp.erase(it);
                    continue;
                }
                it++;
            }
            
            appear[tmp]++;
        }
        
        int maxCount = 0;
        for (auto& p : appear) {
            if (p.second > maxCount) {
                maxCount = p.second;
                answer = p.first;
            } else if (p.second == maxCount && p.first < answer) {
                answer = p.first;
            }
        }
        return answer;
    }
};
