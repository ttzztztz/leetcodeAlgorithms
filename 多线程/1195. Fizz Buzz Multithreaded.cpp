class FizzBuzz {
private:
    int n;
    int i = 1;

    mutex mu;
    condition_variable cv;

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (i <= n) {
            unique_lock<mutex> lk(mu);
            cv.wait(lk, [&]() -> bool {
                return i > n || (i % 3 == 0 && i % 5 != 0);
            });

            if (i <= n) printFizz();

            i++;
            lk.unlock();
            cv.notify_all();
        }
        
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (i <= n) {
            unique_lock<mutex> lk(mu);
            cv.wait(lk, [&]() -> bool {
                return i > n || (i % 3 != 0 && i % 5 == 0);
            });

            if (i <= n) printBuzz();

            i++;
            lk.unlock();
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (i <= n) {
            unique_lock<mutex> lk(mu);
            cv.wait(lk, [&]() -> bool {
                return i > n || (i % 3 == 0 && i % 5 == 0);
            });

            if (i <= n) printFizzBuzz();

            i++;
            lk.unlock();
            cv.notify_all();
        }
        
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (i <= n) {
            unique_lock<mutex> lk(mu);
            cv.wait(lk, [&]() -> bool {
                return i > n || (i % 3 != 0 && i % 5 != 0);
            });

            if (i <= n) printNumber(i);

            i++;
            lk.unlock();
            cv.notify_all();
        }
        
    }
};