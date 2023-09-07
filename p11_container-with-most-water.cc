#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int i = 0, j = height.size() - 1;
        while(i < j) {
            auto tmp = (j - i) * min(height[i], height[j]);
            res = max(res, tmp);
            if(height[i] < height[j])
                i ++;
            else
                j --;
        }
        return res;
    }
};