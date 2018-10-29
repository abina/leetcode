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

