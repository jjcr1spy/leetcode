#include <string>
#include <cwctype> 

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;

        while (i < j) {
            while (!iswalnum(s[i]) && i < j) i++;
            while (!iswalnum(s[j]) && i < j) j--;

            if (tolower(s[i]) != tolower(s[j])) return false;
            
            i++;
            j--;
        }

        return true;
    }
};