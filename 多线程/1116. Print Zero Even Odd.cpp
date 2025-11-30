class ZeroEvenOdd {
private:
    int n;

    int next_number = 1;
    bool expect_zero = true;

    mutex mu;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lk(mu);
            cv.wait(lk, [&]() -> bool {
                return expect_zero == true;
            });
            
            printNumber(0);
            expect_zero = false;

            lk.unlock();
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 1; i < n; i += 2) {
            unique_lock<mutex> lk(mu);
            cv.wait(lk, [&]() -> bool {
                return expect_zero == false && next_number % 2 == 0;
            });
            
            printNumber(next_number);

            next_number++;
            expect_zero = true;

            lk.unlock();
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 0; i < n; i += 2) {
            unique_lock<mutex> lk(mu);
            cv.wait(lk, [&]() -> bool {
                return expect_zero == false && next_number % 2 == 1;
            });
            
            printNumber(next_number);

            next_number++;
            expect_zero = true;

            lk.unlock();
            cv.notify_all();
        }
    }
};