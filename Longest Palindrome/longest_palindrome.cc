#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        int alphabet[58] = {0};
        int length = 0, max_odd_length = 0;

        for(int ix = 0; ix < s.length(); ++ix) {
            ++alphabet[s[ix] - 'A'];
        }
        
        for (int ix = 0; ix < 58; ++ix) {
            std::cout << static_cast<char>('A' + ix) << " -> " << alphabet[ix] << std::endl;
        }

        for (int ix = 0; ix < 58; ++ix) {
            if (alphabet[ix] & 1) {
                if (alphabet[ix] > max_odd_length) {
                    max_odd_length = alphabet[ix];
                }
            } else {
                length += alphabet[ix];
            }
        }

        length += max_odd_length;
        return length;
    }
};

int main() {
    std::ifstream ios("./str.txt");
    if (!ios) {
        return -1;
    }
    
    std::string str;
    ios >> str;
    
    Solution s;
    std::cout << s.longestPalindrome(str) << std::endl;
    
    return 0;
}
