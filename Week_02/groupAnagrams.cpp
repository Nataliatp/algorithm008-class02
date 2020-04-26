//利用异位词在经过排序之后是相同的这个性质，我们在遍历,排序的过程中同时利
//用map记录异位词，最后直接遍历map，将其value值压入数组中
class Solution {
    unordered_map<string, vector<string>> m;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        for (auto& e : strs) {
            string tt = e;
            std::sort(e.begin(), e.end());
            m[e].emplace_back(tt);
        }
        
        for (auto& e : m) {
            ans.emplace_back(e.second);
        }

        return ans;
    }
};

//题解未优化：
//t拷贝原数组内容；
//排序原数组；
//map保存：key为排序后的异位词，value为原异位词的下标；
//words保存所有排序后的异位词
//遍历words找到map中的key，再遍历map找到排序相同的异位词的下标，再根据下标到t中找到原字符串保存到新的vector中，然后再放入最终的数组ans中返回
class Solution {
    unordered_map<string, vector<int>> m;
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        m.clear();
        vector<vector<string>> ans;
        vector<string> t = strs, words;
        for (auto& e : strs) {
            std::sort(e.begin(), e.end());
        }

        for(int i = 0; i < strs.size(); ++i) {
            if(m[strs[i]].empty()) {
                words.emplace_back(strs[i]);
            }
            m[strs[i]].emplace_back(i);
        }

        for(auto& e : words) {
            vector<string> temp;
            for (auto& v : m[e]) {
                temp.emplace_back(t[v]);
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};






