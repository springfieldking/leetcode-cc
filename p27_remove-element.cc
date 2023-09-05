#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 0;
        while(j <nums.size()) {
            nums[i] = nums[j];
            if(nums[i] != val)
              i++;
            j++;
        }
        return i;
    }
};

void main() {
    Solution s;
    vector<int> nums1 = {3,2,2,3};
    vector<int> nums2 = {0,1,2,2,3,0,4,2};

    s.removeElement(nums1, 3);
    for(auto i : nums1) {
        std::cout << i << ',';
    }
    std::cout << std::endl;
}