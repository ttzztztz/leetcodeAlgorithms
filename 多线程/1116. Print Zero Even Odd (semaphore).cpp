class ZeroEvenOdd {
private:
    binary_semaphore sem_zero{1};
    binary_semaphore sem_even{0};
    binary_semaphore sem_odd{0};
private:
    int n;
    int next_val = 1;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++) {
            sem_zero.acquire();
            printNumber(0);

            if (next_val % 2 == 1) {
                sem_odd.release();
            } else {
                sem_even.release();
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 1; i < n; i += 2) {
            sem_even.acquire();
            printNumber(next_val);
            next_val++;
            sem_zero.release();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 0; i < n; i += 2) {
            sem_odd.acquire();
            printNumber(next_val);
            next_val++;
            sem_zero.release();
        }
    }
};