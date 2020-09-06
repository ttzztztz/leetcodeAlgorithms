class Solution {
public:
    /**
     * @param nums: the input array
     * @return: return the longest super sequence
     */
    vector<int> longestSuperSequence(vector<int> &nums) {
        const int N = nums.size();
        
        unordered_map<int, int> numberToAppear;
        map<int, vector<int>, greater<>> appearToNumber;
        for (int i : nums) numberToAppear[i]++;
        for (auto& p : numberToAppear) appearToNumber[p.second].push_back(p.first);
        
        vector<int> sortedAppear;
        for (auto& p : appearToNumber) {
            for (auto& f : p.second) sortedAppear.push_back(f);
        }
        const int M = sortedAppear.size();
        
        unordered_map<int, int> currentAnswer;
        int currentAnswerSize = 0;
        
        int maxAppear = N;
        for (auto& p : appearToNumber) {
            const vector<int>& allNumber = p.second;
            maxAppear = min(maxAppear, p.first);
            cout << maxAppear << " ";
            
            unordered_map<int, int> tmp;
            int numberSize = 0;
            
            for (int i = 0; i < M; i++) {
                if (numberToAppear[sortedAppear[i]] < maxAppear) break;
                
                tmp[sortedAppear[i]] = maxAppear;
                numberSize += maxAppear;
            }
            
            if (numberSize == N && tmp.size() > 1) {
                numberSize -= tmp.begin()->second - 1;
                tmp.begin()->second = 1;
            } else {
                for (int i = 0; i < M; i++) {
                    const int num = sortedAppear[i];
                    if (numberToAppear[num] > tmp[num]) {
                        tmp[num]++;
                        numberSize++;
                        break;
                    }
                }
            }
            
            if (numberSize > currentAnswerSize) {
                currentAnswer = tmp;
                currentAnswerSize = numberSize;
            }
        }
        
        vector<int> answer;
        for (int i = 0; i < N; i++) {
            const int num = nums[i];
            if (currentAnswer.count(num) && currentAnswer[num] > 0) {
                answer.push_back(num);
                currentAnswer[num]--;
                if (currentAnswer[num] == 0) {
                    currentAnswer.erase(num);
                }
            }
        }
        return answer;
    }
};
