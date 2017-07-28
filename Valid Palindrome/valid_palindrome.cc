#include <string>
#include <cctype>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }
        
        string trans = "";
        for(int ix = 0; ix < s.length(); ++ix) {
            if (isalnum(s[ix])) {
                trans.append(1, tolower(s[ix]));
            }
        }

        for(int ix = 0, jx = trans.length() - 1; ix < jx; ++ix, --jx) {
            if (trans[ix] != trans[jx]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;

    return 0;
}
