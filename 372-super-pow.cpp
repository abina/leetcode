#define MODBASE 1337

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int n = b.size();
        if (n == 0) {
            return 1;
        }
        
        int power = 1;
        a = a % MODBASE;
        for (int i = 0; i < n; i++) {
            power = (powMod(power, 10) * powMod(a, b[i])) % MODBASE;
        }
        
        return power;
    }

private:
    int powMod(int a, int b) {        
        int power = 1;
        for (int i = 0; i < b; i++) {
            power = (power * a) % MODBASE;
        }
        
        return power;
    }
};

