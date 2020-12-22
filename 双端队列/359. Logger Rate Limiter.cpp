class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        while (!time_window_.empty() && time_window_.front().first + 10 <= timestamp) {
            auto [timestamp, msg] = time_window_.front();
            time_window_.pop_front();
            
            appear_count_[msg]--;
            if (appear_count_[msg] == 0) appear_count_.erase(msg);
        }
        
        const bool ans = !appear_count_.count(message);
        if (ans) {
            appear_count_[message]++;
            time_window_.emplace_back(timestamp, message);
        }
        return ans;
    }
private:
    unordered_map<string, int> appear_count_;
    deque<pair<int, string>> time_window_;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
