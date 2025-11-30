class DiningPhilosophers {
private:
    mutex mu[5];
public:
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        
        int lock_id1 = philosopher == 0 ? 4 : philosopher - 1;
        int lock_id2 = philosopher;

        if (lock_id1 > lock_id2) swap(lock_id1, lock_id2);

        lock_guard g1(mu[lock_id1]);
        lock_guard g2(mu[lock_id2]);

        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
    }
};