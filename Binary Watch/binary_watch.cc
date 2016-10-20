#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> svec;
        vector<string> hours = {"0", "1", "2", "4", "8"};
        vector<string> minutes = {"00, "01", "02", "04", "08", "16", "32"};
        
        if (num <= 0) {
            return svec;
        }

        int hour = 0, minute = 0;
        for (int ix = 0; ix < num; ++ix) {
            for(int jx = 0; jx < num; ++jx) {
               for(int kx =  

    }
};

int main() {
    Solution s;
    int n;

    std::cout << "Input an integer: " ;
    std::cin >> n;

    vector<string> svec = s.readBinaryWatch(n);
    for (const item& : svec) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    return 0;
}
