class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> m;
        vector<int> result;
        for(int i=0; i<numbers.size(); i++){
            // not found the second one
            if (m.find(numbers[i])==m.end() ) { 
                // store the first one poisition into the second one's key
                m[target - numbers[i]] = i; 
            }else { 
                // found the second one
                result.push_back(m[numbers[i]]+1);
                result.push_back(i+1);
                break;
            }
        }
        return result;
    }
};

