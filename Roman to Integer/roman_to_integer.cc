#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int current = 0, sum = 0;

        for(int ix = 0; ix < s.length(); ) {
            char c = s[ix];
            switch(c) {
                case 'M':
                    current = 1000;
                    ++ix;
                    break;
                case 'D':
                    current = 500;
                    ++ix;
                    break;
                case 'C':
                    if(s[ix + 1] == 'M') {
                        current = 900;
                        ix += 2;
                    } else if(s[ix + 1] == 'D') {
                        current = 400;
                        ix += 2;
                    } else {
                        current = 100;
                        ++ix;
                    }
                    break;
                case 'L':
                    current = 50;
                    ++ix;
                    break;
                case 'X':
                    if(s[ix + 1] == 'C') {
                        current = 90;
                        ix += 2;
                    } else if(s[ix + 1] == 'L') {
                        current = 40;
                        ix += 2;
                    } else {
                        current = 10;
                        ++ix;
                    }
                    break;
                case 'V':
                    current = 5;
                    ++ix;
                    break;
                case 'I':
                    if(s[ix + 1] == 'X') {
                        current = 9;
                        ix += 2;
                    } else if(s[ix + 1] == 'V') {
                        current = 4;
                        ix += 2;
                    } else {
                        current = 1;
                        ++ix;
                    }
                    break;
            }
            sum += current;
        }

        return sum;
    }
};

int main() {
    Solution s;
    string str;

    std::cin >> str;
    std::cout << s.romanToInt(str) << std::endl;
    return 0;
}
