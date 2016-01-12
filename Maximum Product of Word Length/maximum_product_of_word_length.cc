#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        char flag[] = {0};
        int length = words.size();
        int max_len = 0;
        vector<int> str_num_maps;

        sort(words.begin(), words.end(), [](const string& a, const string& b) {return a.length() > b.length();} );
        for(int ix = 0; ix < length; ++ix) {
            str_num_maps.push_back(str_to_num(words[ix]));
        }

        for(int ix = 0; ix < length; ++ix) {
            int num_a = str_num_maps[ix];
            int self_product = words[ix].length() * words[ix].length();
            if (self_product <= max_len) {
                break;
            }

            for(int jx = ix + 1; jx < length; ++jx) {
                int num_b = str_num_maps[jx];
                int len = words[ix].length() * words[jx].length();
                if (!(num_a & num_b) && len > max_len) {
                    max_len = len;
                }
            }
        }

        return max_len;
    }

private:
    int str_to_num(string str) {
        int length = str.length();
        int result = 0;
        for(int ix = 0; ix < length; ++ix) {
            result |= (1 << str[ix] - 'a');
        }

        return result;
    }
};

int main() {
    Solution s;
    vector<string> svec;
    svec.push_back("a");
    svec.push_back("aa");
    svec.push_back("ccc");
    svec.push_back("aaaa");
    svec.push_back("aaaaa");
    svec.push_back("dddddd");

    std::cout << s.maxProduct(svec) << std::endl;

    return 0;
}
