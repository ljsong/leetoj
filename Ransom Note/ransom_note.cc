#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.empty()) {
            return true;
        }

        if (magazine.empty()) {
            return false;
        }

        map<char, int> counts;
        for(size_t ix = 0; ix < magazine.length(); ++ix) {
            counts[magazine[ix]]++;
        }

        for(size_t ix = 0; ix < ransomNote.length(); ++ix) {
            if (--counts[ransomNote[ix]] < 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;

    string ransomNote, magazine;
    std::cout << "Input two strings: " << std::endl;
    std::cin >> ransomNote >> magazine;

    std::cout << "Can construct? " << (s.canConstruct(ransomNote, magazine) ? "YES" : "NO") << std::endl;

    return 0;
}
