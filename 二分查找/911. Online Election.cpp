class TopVotedCandidate {
public:
    vector<int> tempAnswer;
    vector<int> allTimes;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        allTimes = times;
        
        const int N = persons.size();
        unordered_map<int, int> appear;
        int answer = 0, maxVal = 0;
        
        for (int i = 0; i < N; i++) {
            appear[persons[i]]++;
            if (appear[persons[i]] >= maxVal) {
                answer = persons[i];
                maxVal = appear[persons[i]];
            }
            tempAnswer.push_back(answer);
        }
        
    }
    
    int q(int t) {
        auto it = lower_bound(allTimes.begin(), allTimes.end(), t);
        if (it == allTimes.end()) {
            return *tempAnswer.rbegin();
        }
        
        if (*it == t) {
            return tempAnswer[it - allTimes.begin()];
        }
        
        if (it == allTimes.begin()) {
            return 0;
        }
        
        it--;
        return tempAnswer[it - allTimes.begin()];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
