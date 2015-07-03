#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex < 0) {
            return vector<int>();
        }

        if(rowIndex == 0) {
            return vector<int>(1, 1);
        } else if(rowIndex == 1) {
            return vector<int>(2, 1);
        } else {
            vector<int> ivec(rowIndex + 1);
            ivec[0] = ivec[1] = 1;

            for(int ix = 1; ix < rowIndex; ++ix) {
                int last_number = 1, jx = 1;
                int temp = 0;
                for(; jx <= ix; ++jx) {
                    temp = ivec[jx];
                    ivec[jx] = ivec[jx] + last_number;
                    last_number = temp;
                }
                ivec[jx] = 1;
            }

            return ivec;
        }
    }
};

int main() {
    Solution s;
    int n;
    std::cin >> n;

    vector<int> ivec = s.getRow(n);

    for(int ix = 0; ix < ivec.size(); ++ix) {
        std::cout << ivec[ix] << " ";
    }
    std::cout << std::endl;

    return 0;
}
