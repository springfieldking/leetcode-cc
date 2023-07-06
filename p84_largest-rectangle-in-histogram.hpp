#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        stack<int> st;
        for(int i = 0; i < heights.size(); i ++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int cur = st.top();
                st.pop();

                int r = i - 1;
                int l = st.top() + 1;
                ans = max(ans, (r - l + 1) * heights[cur]);
            }
            st.push(i);
        }
        return ans;
    }
};