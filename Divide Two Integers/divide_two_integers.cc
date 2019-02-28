#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {       
        dividend = dividend >= 0 ? dividend : ~dividend + 1;    
        divisor = divisor >= 0 ? divisor : ~divisor + 1;  
        unsigned int count = 0;
        
        for(int ix = 30; ix >= 0; --ix) {  
            if((dividend >> ix) >= divisor) {            
                count += 1 << ix;          
                dividend -= divisor << ix;        
            }    
        }    
  
        if((dividend ^ divisor) < 0){
            count = ~count + 1;  
        }
            
        return count;
    }
};

int main() {
    Solution s;
    int a, b;

    std::cout << "Please input dividend: " << std::endl;
    std::cin >> a;

    std::cout << "Please input divisor: " << std::endl;
    std::cin >> b;

    std::cout << "Answer is: " << s.divide(a, b) << std::endl;
    return 0;
}
