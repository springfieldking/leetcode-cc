#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // 单调栈
        int ans = 0;
        stack<int> st;
        for(int i = 0; i < height.size(); i++) {
            // 栈顶内数据比最新的数据小的出栈, 并计算空间大小
            while(!st.empty() && height[st.top()] < height[i]) {
                // 弹出一个元素
                int cur = st.top();
                st.pop();
                if(st.empty()) break; // 没有元素则没必要计算空间
                // 计算空间差值
                int l = st.top();
                int r = i;
                int h = min(height[r], height[l]) - height[cur];
                // 累计
                ans += (r - l - 1) * h;
            }
            st.push(i);
        }
        return ans;
    }
};