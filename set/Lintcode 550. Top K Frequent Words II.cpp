class TopK {
public:
    /*
    * @param k: An integer
    */
    TopK(int k) {
        // do intialization if necessary
        this->k = k;
    }

    /*
     * @param word: A string
     * @return: nothing
     */
    void add(string &word) {
        if (!app.count(word)) {
            app[word] = 1;
            freq[1].insert(word);
        } else {
            const int prev = app[word];
            app[word]++;
            freq[prev].erase(word);
            if (freq[prev].empty()) freq.erase(prev);
            freq[app[word]].insert(word);
        }
    }

    /*
     * @return: the current top k frequent words.
     */
    vector<string> topk() {
        vector<string> answer;
        for (const auto& p : freq) {
            const set<string>& s = p.second;
            
            for (const string& str : s) {
                if (answer.size() == k) return answer;
                answer.push_back(str);
            }
        }
        return answer;
    }
private:
    unordered_map<string, int> app;
    map<int, set<string>, greater<>> freq;
    int k;
};
