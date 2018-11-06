// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n < 1) {
            return 0;
        }
        
        int l = 1;
        int r = n;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (!isBadVersion(m)) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        
        return l;
    }
};

