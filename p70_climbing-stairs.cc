#include <iostream>
#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) {
            return 0;
        }

        if(n == 1) {
            return 1;
        }

        if(n == 2) {
            return 2;
        }

        return climbStairs(n - 1) + climbStairs(n - 2);
    }

    int climbStairs2(int n) {
        if(n == 0) {
            return 0;
        }

        if(n == 1) {
            return 1;
        }

        if(n == 2) {
            return 2;
        }

        std::vector<int> dp;
        dp.resize(n + 1);
        
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i -2];
        }
        return dp[n];
    }

    int climbStairs3(int n) {

        if(n == 0) {
            return 0;
        }

        if(n == 1) {
            return 1;
        }

        if(n == 2) {
            return 2;
        }

        int x = 0;
        int y = 1;
        int z = 2;
        for(int i = 3; i <= n; i ++) {
            x = y;
            y = z;
            z = x + y;
        }
        return z;
    }
};


void main() {
    Solution s;
    for(int i = 0; i <= 10; i ++) {
        std::cout << "===== test " << i << " =====" << std::endl;
        std::cout << s.climbStairs(i) << std::endl;
        std::cout << s.climbStairs2(i) << std::endl;
        std::cout << s.climbStairs3(i) << std::endl;
    }
    
}