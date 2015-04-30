#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ivec;
        unsigned int ix = 1, upper = (1 << n) - 1;

        ivec.push_back(0);
        while(ix <= upper) {   
            ivec.push_back(ix ^ (ix >> 1)); 
            ++ix;
        }

        return ivec;
    }
};

int main() {
    Solution s;
    int n;
    std::cin >> n;
    vector<int> ivec = s.grayCode(n);

    for(int ix = 0; ix < ivec.size(); ++ix) {
        std::cout << ivec[ix] << " ";
    }

    std::cout << std::endl;

    return 0;
}
