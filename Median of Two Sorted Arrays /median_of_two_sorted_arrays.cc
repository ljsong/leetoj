#include <iostream>
#include <vector>

using namespace std;

class Solution
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length1 = nums1.size();
        int length2 = nums2.size();
        
        if (length1 == 0 && length2 == 0) {
            return 0;
        } else if (length1 == 0) {
            return getMedian(nums2, length2);
        } else {
            return getMedian(nums1, length1);
        }         

        return findMedian(nums1, nums2);
    }

private:
    inline double getMedian(vector<int>& nums, int length) {
        int left = length / 2;
        int right = (length - 1) / 2;

        return nums[left] + nums[right] * 1.0 / 2;
    }

};
