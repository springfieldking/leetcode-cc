#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        // 根据开始时间排序
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < intervals.size() - 1; i ++) {
            // 如果前后有交集
            if(intervals[i][1] > intervals[i+1][0]) {
                return false;
            }
        }
        return true;
    }
};