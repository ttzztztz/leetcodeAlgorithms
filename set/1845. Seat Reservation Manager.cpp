class SeatManager {
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) t.insert(i);
    }
    
    int reserve() {
        auto ans = *t.begin();
        t.erase(t.begin());
        return ans;
    }
    
    void unreserve(int seatNumber) {
        t.insert(seatNumber);
    }
private:
    set<int> t;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */