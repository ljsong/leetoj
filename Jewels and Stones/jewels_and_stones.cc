#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        char alphabet[58] = {0};
        int index = -1, total = 0;

        for (int ix = 0; ix < J.length(); ++ix) {
            alphabet[J[ix] - 0x41] = 1;
        }

        for (int ix = 0; ix < S.length(); ++ix) {
            index = S[ix] - 0x41; 
            total = alphabet[index] == 1 ? ++total : total;
        }

        return total;
    }
};

int main() {
    Solution s;
    std::string jewels, stones;

    std::cout << "Input jewels: " << std::endl;
    std::cin >> jewels;

    std::cout << "Input stones: " << std::endl;
    std::cin >> stones;

    std::cout << s.numJewelsInStones(jewels, stones) << std::endl;

    return 0;
}
