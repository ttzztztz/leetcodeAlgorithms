class FreqStack {
public:
    map<int, vector<int>> frequencyToStack;
    unordered_map<int, int> dataToFrequency;

    FreqStack() {}

    void push(int x) {
        dataToFrequency[x]++;
        frequencyToStack[dataToFrequency[x]].push_back(x);
    }

    int pop() {
        auto it = prev(frequencyToStack.end());
        int answer = it->second.back();
        it->second.pop_back();

        if (it->second.size() == 0) {
            frequencyToStack.erase(it);
        }
        if (dataToFrequency[answer] == 1) {
            dataToFrequency.erase(answer);
        } else {
            dataToFrequency[answer]--;
        }

        return answer;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */