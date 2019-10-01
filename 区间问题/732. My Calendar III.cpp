class CalendarItem {
public:
    int time, factor;
    CalendarItem() : time(0), factor(0) {};
    CalendarItem(int i, int f) : time(i), factor(f) {};
    bool operator<(const CalendarItem& $2) const {
        return this->time < $2.time;
    }
};

class MyCalendarThree {
public:
    set<CalendarItem> list;
    MyCalendarThree() {}

    int total() {
        auto it = list.begin();
        int maxSum = 0, currentSum = 0;
        while (it != list.end()) {
            currentSum += it->factor;
            maxSum = std::max(maxSum, currentSum);

            it++;
        }
        return maxSum;
    }

    int book(int start, int end) {
        auto startIterator = std::lower_bound(list.begin(), list.end(), CalendarItem(start, 1), [](const CalendarItem& $1, const CalendarItem& $2)->bool {
            return $1.time < $2.time;
        });
        if (startIterator != list.end() && startIterator->time == start) {
            int newFactor = startIterator->factor + 1;
            list.erase(startIterator);
            list.insert(CalendarItem(start, newFactor));
        } else {
            list.insert(CalendarItem(start, 1));
        }

        auto endIterator = std::lower_bound(list.begin(), list.end(), CalendarItem(end, -1), [](const CalendarItem& $1, const CalendarItem& $2)->bool {
            return $1.time < $2.time;
        });
        if (endIterator != list.end() && endIterator->time == end) {
            int newFactor = endIterator->factor - 1;
            list.erase(endIterator);
            list.insert(CalendarItem(end, newFactor));
        } else {
            list.insert(CalendarItem(end, -1));
        }
        return total();
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */