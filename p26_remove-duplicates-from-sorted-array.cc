#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // p,q之前是重复字段区域, 需要被覆盖
        // p指向的第一个重复的字段(只有一个也可以理解为重复一次)
        // q指向下一个不重复的字段
        // 不断填充pq之间的数据
        int p = 0, q = 1;
        while(q < nums.size()) {
            if(nums[p] != nums[q]) {
                // 说明中间有重复区间, 1个重复也是重复(这里可以优化, 只有一个重复可以不用覆盖)
                nums[p + 1] = nums[q];
                p++;
            }
            q ++;
        }

        // 最后p + 1都是不重复的
        return p + 1;
    }
};