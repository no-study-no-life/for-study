/*
 * @lc app=leetcode.cn id=1912 lang=cpp
 *
 * [1912] 设计电影租借系统
 */

// @lc code=start
# include <vector>
# include <initializer_list>
# include <unordered_map>
# include <set>
# include <tuple>

using std::vector;
using std::unordered_map;
using std::set;
using std::tuple;
using std::initializer_list;
using std::get;

class MovieRentingSystem {
    unordered_map<unsigned long long, int> total;  // 总表, {(shop, movie): price}
    unordered_map<int, set<unsigned long long>> still; // 未租借表, {movie: {(price, shop), }}
    set<tuple<int, int, int>> rented;  // 已租借表, (price, shop, movie);
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        // 最后, 由于电影表的值删除, 需要price和shop, 因此需要一个总表记录
        // movie, price, shop之间的对应关系, 且返回要求商店编号优先在前, 
        // 而由于一家商店只能有一部电影的一个副本, 因此可以选用(shop, movie)为键, price为值;
        // map<long long, int>;
        int shop, movie, price;
        unsigned long long tmp;
        for(const auto &entry: entries){
            shop = entry[0]; movie = entry[1]; price = entry[2];
            tmp = shop;
            tmp = (tmp << 32) | movie;
            total[tmp] = price;  // 总表: (shop, movie) : price
            tmp = price;
            tmp = (tmp << 32) | shop;
            still[movie].emplace(tmp);  // 未租借表: movie: {(price, shop)}
        }

    }
    
    vector<int> search(int movie) {
        // 根据指定电影查找拥有该电影且最便宜的至多5个商店;
        // 需要根据电影, 因此该表中键为movie, 值为price, shop, 且为有序集合;
        // 假定为未借出 movie 表;
        // 由于需要支持增删操作, 因此可以选用unordered_map<int, set<long long>>;
        if(!still.count(movie))return {};
        vector<int> ans;
        int i = 0, mask = INT_MAX, tmp;
        unsigned long long cur;
        for(auto it = still[movie].begin(); i < 5 && it != still[movie].end(); ++i, ++it){
            cur = *it;
            tmp = (mask & cur);
            ans.push_back(tmp);
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        // 将指定电影从指定商店借出
        unsigned long long tmp = shop;
        tmp = (tmp << 32) | movie;
        int price = total[tmp];  // 从总表处获取价格信息
        tmp = price;
        tmp = (tmp << 32) | shop;  // 根据(价格, 商店)生成的值更新未租借表
        still[movie].erase(tmp);
        // 更新已租借表
        rented.emplace(price, shop, movie);
    }
    
    void drop(int shop, int movie) {
        // 将指定电影返还指定商店
        unsigned long long tmp = shop;
        tmp = (tmp << 32) | movie;
        int price = total[tmp];  // 获取价格信息
        rented.erase({price, shop, movie}); // 更新已租借表
        tmp = price;
        tmp = (tmp << 32) | shop;
        still[movie].emplace(tmp);  // 更新未租借表
    }
    
    vector<vector<int>> report() {
        // 报告已借出的最便宜至多5部电影
        // 需要维护一个已借出表, 且按价格, 商店id, 电影编号排序;
        // 同样需要支持增删操作, 选用set<tuple<price, shop, movie>>;
        vector<vector<int>> ans;
        int i = 0;
        for(auto it = rented.begin(); i < 5 && it != rented.end(); ++i, ++it){
            ans.emplace_back(initializer_list<int>{get<1>(*it), get<2>(*it)});
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
// @lc code=end

