class Solution {
public:
    unordered_map<char, int> statics;
    unordered_map<char, int> tempStatics;
    bool judge() {
        for (const pair<char, int>& temp : tempStatics) {
            if (temp.second != statics[temp.first]) return false;
        }
        return true;
    }
    vector<int> partitionLabels(string S) {
        vector<int> answer;
        for (const char ch : S) statics[ch]++;
        
        const int N = S.size();
        int leftPtr = 0, rightPtr = 0;
        while (rightPtr < N) {
            tempStatics[S[rightPtr]]++;
            
            if (judge()) {
                answer.push_back(rightPtr - leftPtr + 1);
                rightPtr++;
                leftPtr = rightPtr;
                tempStatics.clear();
            } else {
                rightPtr++;
            }
        }
        
        return answer;
    }
};
