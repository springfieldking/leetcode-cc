#include <vector>
using namespace std;

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    // 申请
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    int** dp = new int*[m];
    for (int i = 0; i < m; i++) {
      dp[i] = new int[n];
      for (int j = 0; j < n; j++) {
        dp[i][j] = 0;
      }
    }


    // 边缘初始化
    for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) {
        dp[i][0] = 1;
    };
    for (int j = 0; j < n &&obstacleGrid[0][j] == 0; j++) {
        dp[0][j] = 1;
    }
    // dp[i][j] = dp[i-1][j]＋dp[i][j-1]
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if(obstacleGrid[i][j] == 0)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }

    int ret = dp[m-1][n-1];
    // 释放
    for (int i = 0; i < m; i++) {
      delete[] dp[i];
    }
    delete[] dp;

    return ret;
  }
};

void main() {}