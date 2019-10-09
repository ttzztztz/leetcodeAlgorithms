class Character {
public:
    char ch;
    int time;
    Character() : ch(0), time(0) {};
    Character(int c, int t) : ch(c), time(t) {};
    bool operator<(const Character& $2) const {
        return this->time < $2.time;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> frequency;
        priority_queue<Character> heap;
        for (int i = 0; i < s.size(); i++) {
            if (!frequency.count(s[i])) {
                frequency[s[i]] = 1;
            } else {
                frequency[s[i]]++;
            }
        }
        for (const pair<char, int>& ch : frequency) {
            heap.push(Character(ch.first, ch.second));
        }

        string result;
        result.resize(s.size());
        int ptr = 0;
        while (!heap.empty()) {
            Character ch = heap.top();
            heap.pop();
            for (int i = 0; i < ch.time; i++) {
                result[ptr++] = ch.ch;
            }
        }
        return result;
    }
};