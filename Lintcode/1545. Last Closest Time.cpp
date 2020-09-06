class Solution {
public:
    /**
     * @param time: 
     * @return: return a string represent time
     */
    string lastTime(string &time) {
        if (time.size() != 5) return "-1";
        int minutes = stoi(time.substr(0, 2)), seconds = stoi(time.substr(3, 2));
        
        if (minutes < 0 || minutes > 23) return "-1";
        if (seconds < 0 || seconds > 59) return "-1";
        
        seconds--;
        if (seconds < 0) {
            seconds += 60;
            minutes--;
        }
        
        if (minutes < 0) {
            minutes += 24;
        }
        
        string str_minutes = to_string(minutes), str_seconds = to_string(seconds);
        
        if (str_minutes.size() == 1) str_minutes = '0' + str_minutes;
        if (str_seconds.size() == 1) str_seconds = '0' + str_seconds;
    
        return str_minutes + ":" + str_seconds;
    }
};
