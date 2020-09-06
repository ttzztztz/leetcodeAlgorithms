class ExamRoom {
public:
    ExamRoom(int N) {
        this->N = N;
    }
    
    int seat() {
        int last = 0, maxAnswer = 0, answer;
        if (pos.empty()) {
            pos.insert(0);
            return 0;
        }
        
        if (*pos.begin() != 0) {
            const int d = *pos.begin();
            if (d > maxAnswer) {
                maxAnswer = d;
                answer = 0;
            }
        }
        
        for (int p : pos) {
            const int d = (p - last) / 2;
            if (d > maxAnswer) {
                maxAnswer = d;
                answer = (last + p) / 2;
            }
            last = p;
        }
        
        if (*pos.rbegin() != N - 1) {
            const int d = N - 1 - *pos.rbegin();
            if (d > maxAnswer) {
                maxAnswer = d;
                answer = N - 1;
            }
        }
        
        pos.insert(answer);
        return answer;
    }
    
    void leave(int p) {
        pos.erase(p);
    }
private:
    set<int> pos;
    int N;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
