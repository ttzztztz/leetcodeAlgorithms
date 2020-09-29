class AllOne {
private:
    typedef pair<int, list<string>> FreqItem;
    typedef pair<int, list<string>::iterator> Data;

    unordered_map<string, Data> data;
    list<FreqItem> freqList;
    unordered_map<int, list<FreqItem>::iterator> freqToList;
    int min_freq = numeric_limits<int>::max(), max_freq = numeric_limits<int>::min();

public:
    /** Initialize your data structure here. */
    AllOne() {}

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        int incFreq = 0;

        if (data.count(key)) {
            int freq;
            list<string>::iterator it;

            tie(freq, it) = data[key];
            freqToList[freq]->second.erase(it);
            incFreq = freq + 1;

            if (min_freq == freq && freqToList[freq]->second.empty()) min_freq++;
            max_freq = max(max_freq, incFreq);

            if (!freqToList.count(incFreq)) {
                auto _it = freqToList[freq];
                ++_it;
                freqToList[incFreq] = freqList.insert(_it, make_pair(incFreq, list<string>{}));
            }
        } else {
            incFreq = 1;

            if (!freqToList.count(1)) {
                freqList.emplace_front(1, list<string>{});
                freqToList[incFreq] = freqList.begin();
            }

            min_freq = 1;
            max_freq = max(max_freq, 1);
        }

        freqToList[incFreq]->second.push_back(key);
        auto _it = freqToList[incFreq]->second.end();
        _it--;
        data[key] = {incFreq, _it};

        int freq = incFreq - 1;
        if (incFreq >= 2 && freqToList[freq]->second.empty()) {
            freqList.erase(freqToList[freq]);
            freqToList.erase(freq);
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (!data.count(key)) return;

        int freq;
        list<string>::iterator it;

        tie(freq, it) = data[key];
        freqToList[freq]->second.erase(it);
        int decFreq = freq - 1;

        if (decFreq == 0) {
            data.erase(key);
        } else {
            if (!freqToList.count(decFreq)) {
                freqToList[decFreq] = freqList.insert(freqToList[freq], make_pair(decFreq, list<string>{}));
            }

            freqToList[decFreq]->second.push_back(key);
            data[key] = {decFreq, --freqToList[decFreq]->second.end()};
            min_freq = min(min_freq, max(1, decFreq));
        }

        if (min_freq == freq && freqToList[freq]->second.empty()) {
            auto _it = freqToList[freq];
            ++_it;
            if (_it != freqList.end()) {
                min_freq = _it->first;
            }
        }

        if (freq == max_freq && freqToList[freq]->second.empty()) max_freq--;
        if (freqToList[freq]->second.empty()) {
            freqList.erase(freqToList[freq]);
            freqToList.erase(freq);
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (!freqToList.count(max_freq)) return "";

        auto it = freqToList[max_freq];
        if (!it->second.empty()) {
            return *(it->second.begin());
        }
        return "";
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (!freqToList.count(min_freq)) return "";

        auto it = freqToList[min_freq];
        if (!it->second.empty()) {
            return *(it->second.begin());
        }
        return "";
    }
};
