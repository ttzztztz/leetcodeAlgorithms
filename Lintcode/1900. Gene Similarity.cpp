class Gen {
public:
    int number;
    char ch;
    Gen() : number(0), ch(0) {};
};

class Solution {
public:
    /**
     * @param Gene1: a string
     * @param Gene2: a string
     * @return: return the similarity of two gene fragments
     */
    string GeneSimilarity(string &Gene1, string &Gene2) {
        vector<Gen> g1 = parse(Gene1), g2 = parse(Gene2);
        int total = 0, similar = 0;
        for (auto& p : g1) total += p.number;
        
        const int N = g1.size(), M = g2.size();
        
        int ptr1 = 0, ptr2 = 0;
        int offset1 = 0, offset2 = 0;
        while (ptr1 < g1.size() && ptr2 < g2.size()) {
            if (g1[ptr1].ch == g2[ptr2].ch) {
                similar += min(offset1 + g1[ptr1].number, offset2 + g2[ptr2].number) - max(offset1, offset2);
            }
            
            if (offset1 + g1[ptr1].number <= offset2 + g2[ptr2].number) {
                offset1 += g1[ptr1].number;
                ptr1++;
            } else {
                offset2 += g2[ptr2].number;
                ptr2++;
            }
        }
        
        string answer;
        answer += to_string(similar);
        answer += '/';
        answer += to_string(total);
        return answer;
    }
private:
    vector<Gen> parse(const string& str) {
        vector<Gen> answer;
        string number;
        for (int i = 0; i < str.size(); i++) {
            const char ch = str[i];
            
            if (ch >= '0' && ch <= '9') {
                number += ch;
            } else {
                Gen g;
                g.number = stoi(number);
                g.ch = ch;
                answer.emplace_back(g);
                
                number.clear();
            }
        }
        
        return answer;
    }
};
