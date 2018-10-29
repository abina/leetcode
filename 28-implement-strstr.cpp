//O(m*n)
class Solution {
public:
    int strStr(string haystack, string needle) {        
        int nLen = needle.length();
        if (nLen == 0) {
            return 0;
        }
        
        int hLen = haystack.length();
        for (int i = 0; i < hLen - nLen + 1; i++) {
            int j = 0;
            for (; j < nLen; j++) {
                if (haystack[i+j] != needle[j]) {
                    break;
                }
            }
            if (j == nLen) {
                return i;
            }
        }
        
        return -1;
    }
};


//O(m+n)
#define BASE 1000000;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int nLen = needle.length();
        if (nLen == 0) {
            return 0;
        }
        
        int hLen = haystack.length();
        if (hLen < nLen) {
            return -1;
        }
        
        int fCode = getFirstCode(nLen);
        int hCode = getHashCode(haystack.substr(0, nLen), nLen);
        int nCode = getHashCode(needle, nLen);
        for (int i = 0; i < hLen - nLen + 1; i++) {
            if (hCode == nCode) {
                int j = 0;
                for (; j < nLen; j++) {
                    if (haystack[i+j] != needle[j]) {
                        break;
                    }
                }
                if (j == nLen) {
                    return i;
                }
            }

            hCode = (hCode - haystack[i] * fCode) % BASE;
            if (hCode < 0) {
                hCode += BASE;
            }
            hCode = (hCode * 31 + haystack[i+nLen]) % BASE;
        }
        
        return -1;
    }

private:
    int getFirstCode(int len) {
        int code = 1;
        for (int i = 1; i < len; i++) {
            code = (code * 31) % BASE;
        }
        
        return code;
    }
    
    int getHashCode(string str, int len) {
        int code = 0;
        for (int i = 0; i < len; i++) {
            code = (code * 31 + str[i]) % BASE;
        }
        
        return code;
    }
};

