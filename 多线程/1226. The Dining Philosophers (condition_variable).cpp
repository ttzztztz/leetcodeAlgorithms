class DiningPhilosophers {
private:
    vector<bool> folk_available;

    mutex mu;
    condition_variable cv;
public:
    DiningPhilosophers() {
        folk_available = vector<bool>(5, true);
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        
        const int lock_id1 = philosopher - 1 < 0 ? philosopher - 1 + 5 : philosopher - 1;
        const int lock_id2 = philosopher;

        unique_lock<mutex> lk(mu);
        cv.wait(lk, [&]() -> bool {
            return folk_available[lock_id1] && folk_available[lock_id2];
        });

        folk_available[lock_id1] = false;
        folk_available[lock_id2] = false;

        pickLeftFork();
        pickRightFork();
        
        lk.unlock();
        cv.notify_all();

        eat();

        putLeftFork();
        putRightFork();

        folk_available[lock_id1] = true;
        folk_available[lock_id2] = true;
        cv.notify_all();
    }
};
