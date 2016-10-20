#! /usr/bin/env python
# -*- encoding:utf-8 -*-

class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtyp: List[str]
        """
        numList = []
        for item in range(1, n + 1):
            if item % 15 == 0:
                numList.append("FizzBuzz")
            elif item % 3 == 0:
                numList.append("Fizz")
            elif item % 5 == 0:
                numList.append("Buzz")
            else:
                numList.append(str(item))

        return numList

def main():
    sol = Solution()
    numList = sol.fizzBuzz(15)

    for item in numList:
        print item

if __name__ == '__main__':
    main()
