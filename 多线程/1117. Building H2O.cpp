class H2O {
private:
    mutex mu;
    condition_variable cv;

    int unpairded_hydrogen = 0;
public:
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lk(mu);
        cv.wait(lk, [&]() -> bool {
            return unpairded_hydrogen < 2;
        });
        
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();

        unpairded_hydrogen++;

        lk.unlock();
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lk(mu);
        cv.wait(lk, [&]() -> bool {
            return unpairded_hydrogen >= 1;
        });
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();

        unpairded_hydrogen -= 2;

        lk.unlock();
        cv.notify_all();
    }
};