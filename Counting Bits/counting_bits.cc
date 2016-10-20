#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result;
        result.push_back(0);
        int maxPivot = 0;

        for(int ix = 1; ix <= num; ++ix) {
            if (ix > 1 && (ix & (ix - 1)) == 0) {
                maxPivot= ix;
                result.push_back(1);
            } else {
                result.push_back(result[ix - maxPivot] + 1);
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    int num;

    std::cout << "Input a number: ";
    std::cin >> num;

    vector<int> result = s.countBits(num);
    for (int item : result) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}
