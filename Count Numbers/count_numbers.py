#! /usr/bin/env python
# -*- coding:utf-8 -*-

class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        if n == 0:
            return 1
        elif n == 1:
            return 10 
        elif n > 10:
            return self.countNumbersWithUniqueDigits(10)
        else:
            count = 9
            for ix in range(0, n - 1):
                count *= (9 - ix)
            return count + self.countNumbersWithUniqueDigits(n - 1)
            

def main():
    sol = Solution()
    print sol.countNumbersWithUniqueDigits(99)

if __name__ == '__main__':
    main()
