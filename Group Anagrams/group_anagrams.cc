#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        map<string, vector<string>> keys;
        char alphabet[27] = {0};
        int idx = 0;

        if (strs.empty()) {
            return ret;
        }
        
        for (int ix = 0; ix < strs.size(); ++ix) {
            string key = get_key(strs[ix], alphabet, 26);
            if (keys.find(key) == keys.end()) {
                vector<string> svec;
                svec.push_back(strs[ix]);
                keys[key] = svec;
            }
            else {
                vector<string>& svec = keys[key];
                svec.push_back(strs[ix]);
            }
        }

        for(auto itr = keys.begin(); itr != keys.end(); ++itr) {
            ret.push_back(std::move(itr->second));
        }

        return ret;
    }

private:
    string get_key(string item, char* alphabet, int len) {
        int key = 0;
        memset(alphabet, 0x30, len);
        for(int ix = 0; ix < item.length(); ++ix) {
            alphabet[item[ix] - 'a']++;
        }

        return string(alphabet);
    }
};

int main() {
    Solution s;

    return 0;
}
