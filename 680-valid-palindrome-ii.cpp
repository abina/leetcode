class Solution {
public:
    bool validPalindrome(string s) {
        int len = s.length();
        if (len < 2) {
            return true;
        }
        
        int l = 0;
        int r = len - 1;
        while (l < r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else {
                return helper(s.substr(l, r - l)) || helper(s.substr(l + 1, r - l));
            }
        }
        
        return true;
    }
    
private:
    bool helper(string s) {
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        
        return true;
    }
};

