class TweetCounts {
public:
    unordered_map<string, vector<int>> hashmap;
    TweetCounts() {}
    
    void recordTweet(string tweetName, int time) {
        vector<int>& v = hashmap[tweetName];
        auto it = upper_bound(v.begin(), v.end(), time);
        v.insert(it, time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector<int> answer;
        
        int d = 0;
        if (freq == "minute") {
            d = 60;
        } else if (freq == "hour") {
            d = 3600;
        } else if (freq == "day") {
            d = 86400;
        }
        
        for (int j = 0; startTime + d * j <= endTime; j++) {
            const int b1 = startTime + j * d, b2 = min(startTime + (j + 1) * d, endTime + 1);
            vector<int>& s = hashmap[tweetName];
            
            auto it1 = lower_bound(s.begin(), s.end(), b2);
            auto it2 = lower_bound(s.begin(), s.end(), b1);
            
            answer.push_back(it1 - it2);
            if (b2 == endTime + 1) break;
        }
        
        return answer;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
