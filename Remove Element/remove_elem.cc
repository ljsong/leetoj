#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int k = 0;
        for(int ix = 0; ix < n; ++ix) {
            if(A[ix] == elem) {
                ++k;
            } else {
                A[ix - k] = A[ix];
            }
        }

        return n - k;
    }
};

int main() {
    Solution s;
    int a[] = {1, 2, 3, 4, 2, 5, 4, 4};

    int length = s.removeElement(a, 8, 4);
    for(int ix = 0; ix < length; ++ix) {
        std::cout << a[ix] << " ";
    }
    std::cout << std::endl;

    return 0;
}
