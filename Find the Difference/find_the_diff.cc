#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int count[26] = {0};

        for(int ix = 0; ix < s.size(); ++ix) {
            ++count[s[ix] - 'a'];
        }

        for (int ix = 0; ix < t.size(); ++ix) {
            --count[s[ix] - 'a'];
        }

        for(int ix = 0; ix < 26; ++ix) {
            if (count[ix] > 0) {
                return 'a' + ix;
            }
        }

        return 0;
    }
};

int main() {
    Solution sol;
    std::cout << "Input two strings:";
    string s, t;

    std::cin << s << t;
    std::cout << "Difference is: " << sol.findTheDifference(s, t) << std::endl;
    return 0;
}
