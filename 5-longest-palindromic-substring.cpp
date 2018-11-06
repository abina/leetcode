class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len < 2) {
            return s;
        }

        int start = 0;
        int maxLen = 1;
        for (int i = 0; i < len;) {
            if (len - i <= maxLen / 2) {
                break;
            }
            
            int l = i;
            int r = i;
            while (r < len - 1 && s[r+1] == s[r]) {
                r++;
            }
            i = r + 1;
            
            while (l > 0 && r < len - 1 && s[l-1] == s[r+1]) {
                l--;
                r++;
            }
            
            int newLen = r - l + 1;
            if (newLen > maxLen) {
                start = l;
                maxLen = newLen;
            }
        }
        
        return s.substr(start, maxLen);
    }
};


class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len == 0 || len == 1) {
            return s;
        }
        
        int start = 0;
        int maxLen = 1;
        
        vector<vector<bool>> isPalindrome(len, vector<bool>(len));
        for (int i = 0; i < len; i++) {
            isPalindrome[i][i] = true;
        }
        for (int i = 0; i < len - 1; i++) {
            isPalindrome[i][i+1] = s[i] == s[i+1];
            if (isPalindrome[i][i+1]) {
                start = i;
                maxLen = 2;
            }
        }
        
        for (int l = len - 1; l >= 0; l--) {
            for (int r = l + 2; r < len; r++) {
                isPalindrome[l][r] = isPalindrome[l+1][r-1] && s[l] == s[r];
                if (isPalindrome[l][r] && r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }
            }
        }
        
        return s.substr(start, maxLen);
    }
};

