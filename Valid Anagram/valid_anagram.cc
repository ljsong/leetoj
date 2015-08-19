#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int stats[26] = {0};

        for(int ix = 0; ix < s.length(); ++ix) {
            char ch = s[ix];
            ++stats[ch - 'a'];
        }

        for (int ix = 0; ix < t.length(); ++ix) {
            char ch = t[ix];
            --stats[ch - 'a'];
        }

        for(int ix = 0; ix < 26; ++ix) {
            if (stats[ix] != 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    string u = "anagram";
    string w = "nagaram";

    std::cout << s.isAnagram(u, w) << std::endl;

    return 0;
}
