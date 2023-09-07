#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 这里有个点:只要能到达i点，那么i之前的所有的点都能到,只要disi>nums.size()就说明能到最后一个点
        int disi = 0;
        for(int i = 0; i < nums.size(); i++) {
            // 如果无法到达当前点 直接返回错误
            if(disi < i) return false;

            // 如果当前点开始跳跃的距离比之前的范围还要大则更新最大距离
            if(i + nums[i] > disi)
                disi = i + nums[i];
        }

        // 判断是否能够到达
        return disi >= nums.size() - 1;
    }
};