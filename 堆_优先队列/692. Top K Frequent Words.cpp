class Word {
public:
    string word;
    int frequency;
    Word() : word(""), frequency(0) {};
    Word(string s, int f) : word(s), frequency(f) {};
    bool operator< (const Word& $2) const {
        if (this->frequency == $2.frequency) {
            return this->word < $2.word;
        } else {
            return this->frequency > $2.frequency;
        }
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> map;
        for (const string& word : words) {
            if (!map.count(word)) {
                map[word] = 1;
            } else {
                map[word]++;
            }
        }
        priority_queue<Word> heap;
        for (const pair<string, int>& word : map) {
            heap.push(Word(word.first, word.second));
            if (heap.size() > k) {
                heap.pop();
            }
        }
        vector<string> answer;
        for (int i = 0, n = heap.size(); i < n; i++) {
            answer.push_back(heap.top().word);
            heap.pop();
        }
        std::reverse(answer.begin(), answer.end());
        return answer;
    }
};