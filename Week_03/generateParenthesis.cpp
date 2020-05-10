//括号生成
//执行结果错误,为什么呢？：
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(res, "", 0, 0, n);
        return res;
    }
    void generate(vector<string> res, string current, int lc, int rc, int n) {
        if (lc > n || rc > lc)
            return;
        if (lc == n && lc == rc) {
            res.push_back(current);
            return;
        }
        generate(res, current + '(', lc + 1, rc, n);
        generate(res, current + ')', lc, rc + 1, n);
    }
};

//执行结果错误,为什么呢？
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(res, "", 0, 0, n);
        return res;
    }
    void generate(vector<string> res, string current, int lc, int rc, int n) {
        if (lc == n && lc == rc) {
            res.push_back(current);
            return;
        }
        if (lc < n) generate(res, current + '(', lc + 1, rc, n);
        if (rc < lc) generate(res, current + ')', lc, rc + 1, n);
    }
};

//国际leetcode最优解
class Solution {
    vector<string> res;
    void generate(int n, string curr, int left, int right) {
        if (left + right == 2*n) {
            res.push_back(curr);
        }

        if (left < n) generate(n, curr+'(', left+1, right);
        if (left > right) generate(n, curr+')', left, right+1);
    }
public:
    vector<string> generateParenthesis(int n) {
        string curr;
        generate(n, curr, 0, 0);
        return res;
    }
};

class Solution {
    vector<string> res;
    void generate(int n, string s, int left, int right) {
        if (left == n && right == n) {
            res.push_back(s);
        }
        if (left < n) generate(n, s+'(', left+1, right);
        if (left > right) generate(n, s+')', left, right+1);
    }
public:
    vector<string> generateParenthesis(int n) {
        generate(n, "", 0, 0);
        return res;
    }
};
