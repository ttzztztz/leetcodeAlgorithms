class Solution {
public:
    string lastTime(string &time) {
        if (time.size() != 5) return "-1";
        
        int hour = stoi(time.substr(0, 2)), minute = stoi(time.substr(3, 2));
        if (hour < 0 || hour > 23) return "-1";
        if (minute < 0 || minute > 59) return "-1";
        
        getNext(hour, minute);
        while (isRepeat(hour, minute)) getNext(hour, minute);
        
        string str_hour = to_string(hour), str_minute = to_string(minute);
        if (str_hour.size() == 1) str_hour = '0' + str_hour;
        if (str_minute.size() == 1) str_minute = '0' + str_minute;
        return str_hour + ":" + str_minute;
    }
private:
    void getNext(int& hour, int& minute) {
        minute--;
        
        if (minute < 0) {
            minute += 60;
            hour--;
        }
        if (hour < 0) {
            hour += 24;
        }
    }
    bool isRepeat(const int hour, const int minute) {
        string str_hour = to_string(hour), str_minute = to_string(minute);
        
        if (str_hour.size() == 1) str_hour = '0' + str_hour;
        if (str_minute.size() == 1) str_minute = '0' + str_minute;
        
        if (str_hour[0] == str_hour[1] || str_minute[0] == str_minute[1]) return true;
        
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (str_hour[i] == str_minute[j]) return true;
            }
        }
        
        return false;
    }
};
