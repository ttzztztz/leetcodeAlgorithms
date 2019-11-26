class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, vector<pair<int, string>>> storage;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        if (!storage.count(key)) {
            storage[key] = vector<pair<int, string>>();
        }

        storage[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        if (!storage.count(key)) {
            return "";
        }

        vector<pair<int, string>>& data = storage[key];
        if (data.size() == 0) {
            return "";
        }

        int left = 0, right = data.size() - 1;
        while (left <= right) {
            const int middle = (left + right) >> 1;

            if (data[middle].first <= timestamp) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        left--;
        if (left >= 0) {
            return data[left].second;
        } else {
            return "";
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */