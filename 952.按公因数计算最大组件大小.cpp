/*
 * @lc app=leetcode.cn id=952 lang=cpp
 *
 * [952] 按公因数计算最大组件大小
 */

// @lc code=start
# include <vector>
# include <algorithm>

using std::vector;
using std::max;
using std::max_element;

class UF {
    vector<int> parent;
    vector<int> rank;   // 查找路径长度 
public:
    UF(int n): parent(vector<int>(n)), rank(vector<int>(n)){
        for(int i = 0; i < n; ++i){
            parent[i] = i;
        }
    }

    int find(int x){
        if(x != parent[x]){
            parent[x] = find(parent[x]); // 路径压缩
        }
        return parent[x];
    }

    void uni(int x, int y){
        int a = find(x), b = find(y);
        if(a == b)return;
        // 将较短路径的根节点, 挂在较长的根节点下
        // 当二者路径长度不同时, 查找到较长节点最长路径长度并未改变
        // 相同时, 则选择作为根节点的路径长度需要+1;
        if(rank[a] > rank[b]){
            parent[b] = a; 
        }else if(rank[a] < rank[b]){
            parent[a] = b;
        }else{
            parent[a] = b; 
            ++rank[b];
        }
    }

};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        /*
            如果一个数和现有集合内任意一个数存在大于1的公因数, 则可以将其加入组件内;
            那如何判断是否可以加入呢? 则需要维护一个当前组件的公因数集合, 判断现有数的因子是否存在其中;
            若存在其中, 则可以将当前数的因数更新到该集合中, 否则认为其是下一个组件的元素;
            获取因数不超过O(n), 判断是否在其内也不超过O(n);
            但是维护组件时间可能...;
            可以同时维护多个组件? 但是组件之间可能可以连接;?
            并查集?
        */
        int maxval = *(max_element(nums.begin(), nums.end()));
        UF uf(maxval + 1);
        int ans = 0;
        vector<int> count(maxval + 1);
        for(int num: nums){
            for(int i = 2; i * i <= num; ++i){
                if(num % i == 0){
                    uf.uni(num, i);
                    uf.uni(num, num / i);
                }
            }
        }

        for(int num: nums){
            int root = uf.find(num);
            ++count[root];
            ans = max(ans, count[root]);
        }
        return ans;

    }
};
// @lc code=end

