//爬楼梯
//我自己提交的递归写法，为什么会超时呢？
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

//正确的递归，保留中间值
class Solution {
public:
    unordered_map<int, int> cache;
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (cache.find(n) != cache.end())
            return cache[n];
        int res = climbStairs(n-1) + climbStairs(n-2);
        cache[n] = res;
        return res;
    }
};

//动态规划解法：
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        vector<int>dp(n, 0);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i < n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n-1];
    }
};
