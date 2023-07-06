#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // 根据开始时间排序
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){ return a[0] < b[0]; });
        priority_queue<int, vector<int>, greater<int>> q;
        for(auto & i : intervals) {
            // 队列中最早结束的会议,比当前会议还要早, 说明可以用同一个会议室, 把它弹出 
            if(!q.empty() && q.top() > i[0]) {
                q.pop();
            }
            q.push(i[1]);
        }
        return q.size();
    }
};