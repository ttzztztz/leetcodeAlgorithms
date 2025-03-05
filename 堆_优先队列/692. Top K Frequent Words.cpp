class Data {
public:
    int cnt;
    string word;

    bool operator<(const Data& $2) const {
        if (this->cnt == $2.cnt) {
            return this->word < $2.word;
        }

        return this->cnt > $2.cnt;
    };
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> cnt_hmap;
        for (const string& word : words) cnt_hmap[word]++;

        priority_queue<Data> heap;
        for (auto& [word, cnt] : cnt_hmap) {
            heap.emplace(cnt, word);

            if (heap.size() > k) heap.pop();
        }

        vector<string> ans;
        for (int i = 0; i < k; i++) {
            auto[_, word] = heap.top();
            heap.pop();
            ans.push_back(word);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};