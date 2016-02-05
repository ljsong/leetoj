/* Find all possible combinations of k numbers that add up to a number n, 
 * given that only numbers from 1 to 9 can be used and each combination 
 * should be a unique set of numbers.

 * Ensure that numbers within the set are sorted in ascending order.

 * Example 1:
 * Input: k = 3, n = 7

 * Output:
 * [[1,2,4]]

 * Example 2:
 * Input: k = 3, n = 9

 * Output:
 *[[1,2,6], [1,3,5], [2,3,4]]
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> matrix;

        int sum = k & 1 ? ((k + 1) >> 1) * k : (k >> 1) * (k + 1); 
        if (n < k || sum > n || n > 45) {
            return matrix;
        }

        vector<int> solution;
        set<int> sset;
        findSolution(matrix, solution, sset, k, n, 1);

        return matrix;
    }

private:
    void findSolution(vector<vector<int>>& matrix, vector<int>& solution, set<int>& sset, int k, int remaining, int currentNum) {
        if (k == 0 && remaining == 0) {
            recordSolution(matrix, solution, sset);
            return ;
        }

        int bound = remaining > 9 ? 9 : remaining;
        for(int ix = currentNum; ix <= bound; ++ix) {
            if (ix < remaining && k > 1 || ix == remaining && k == 1) {
                solution.push_back(ix);
                findSolution(matrix, solution, sset, k - 1, remaining - ix, ix + 1);
                solution.pop_back();
            }
        }
    }

    void recordSolution(vector<vector<int>>& matrix, vector<int>& solution, set<int>& sset) {
        int num = 0;
        for(int ix = 0; ix < solution.size(); ++ix) {
            num |= (1 << solution[ix]);
        }

        if (sset.find(num) == sset.end()) {
            matrix.push_back(solution);
            sset.insert(num);
        }
    }
};

int main() {
    Solution s;

    std::cout << "Input n and k: " << std::endl;
    int n, k;
    std::cin >> n >> k;
    vector<vector<int>> matrix = s.combinationSum3(k, n);

    std::cout << "[ ";
    for (int ix = 0; ix < matrix.size(); ++ix) {
        std::cout << "[";
        for(int jx = 0; jx < matrix[ix].size(); ++jx) {
            std::cout << matrix[ix][jx] << " ";
        }
        std::cout << "]";
    }
    std::cout << " ]" << std::endl;

    return 0;
}
