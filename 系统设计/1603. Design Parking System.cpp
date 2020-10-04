class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        memset(f, 0, sizeof f);
        f[0] = big;
        f[1] = medium;
        f[2] = small;
    }
    
    bool addCar(int carType) {
        if (f[carType - 1] >= 1) {
            f[carType - 1]--;
            return true;
        } else return false;
    }
private:
    int f[3];
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
