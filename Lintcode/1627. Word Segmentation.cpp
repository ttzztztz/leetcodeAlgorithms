class Solution {
public:
    /**
     * @param s: the string
     * @param k: the k
     * @return: the answer
     */
    vector<string> wordSegmentation(string &s, int k) {
        stringstream ss;
        ss << s;
        
        vector<string> stk;
        int stkLen = 0;
        
        vector<string> answer;
        string tmp;
        while (ss >> tmp) {
            if (tmp.size() + stkLen + stk.size() > k) {
                string nxtAnswer;
                
                for (int i = 0; i < stk.size(); i++) {
                    if (i != 0) nxtAnswer += ' ';
                    nxtAnswer += stk[i];
                }
                
                answer.push_back(nxtAnswer);
                stk.clear();
                stkLen = 0;
            }
            
            stkLen += tmp.size();
            stk.push_back(tmp);
        }
        
        string nxtAnswer;
                
        for (int i = 0; i < stk.size(); i++) {
            if (i != 0) nxtAnswer += ' ';
            nxtAnswer += stk[i];
        }
                
        answer.push_back(nxtAnswer);
        stk.clear();
        stkLen = 0;
        
        return answer;
    }
};
