#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int ix = 0, partial = 0;
        vector<int> seq;
        vector<string> result;

        compute_solution(seq, result, ix, n, partial);

        return result;
    }

private:
    void compute_solution(vector<int> &seq, vector<string> &result, int ix, int n, int partial) {
        if(ix == n && partial== 0) {
            string str = fill_parentheses(seq);
            result.push_back(str);
            return ;
        } else if(ix == n) {
            seq.push_back(-1);
            compute_solution(seq, result, ix, n, partial - 1);
            seq.pop_back();
        } else if(partial == 0) {
            seq.push_back(1);
            compute_solution(seq, result, ix + 1, n, partial + 1);
            seq.pop_back();
        } else {
            seq.push_back(1);
            compute_solution(seq, result, ix + 1, n, partial + 1);
            seq.pop_back();

            seq.push_back(-1);
            compute_solution(seq, result, ix, n, partial - 1);
            seq.pop_back();
        }
    }

    string fill_parentheses(const vector<int> &seq) {
        char str[256] = {0};
        int ix = 0;

        for(; ix < seq.size(); ++ix) {
            if(seq[ix] == 1) {
                str[ix] = '(';
            } else if(seq[ix] == -1) {
                str[ix] = ')';
            }
        }
        str[ix] = 0;

        return string(str);
    }
};

int main() {
    Solution s;
    vector<string> svec = s.generateParentheses(3);
    for(int ix = 0; ix < svec.size(); ++ix) {
        std::cout << svec[ix] << std::endl;
    }

    return 0;
}
