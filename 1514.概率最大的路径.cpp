/*
 * @lc app=leetcode.cn id=1514 lang=cpp
 *
 * [1514] 概率最大的路径
 */

// @lc code=start
# include <vector>
# include <queue>
# include <utility>

using std::vector;
using std::priority_queue;
using std::pair;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<double, int>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            auto& e = edges[i];
            graph[e[0]].emplace_back(succProb[i], e[1]);
            graph[e[1]].emplace_back(succProb[i], e[0]);
        }

        priority_queue<pair<double, int>> que;
        vector<double> prob(n, 0);

        que.emplace(1, start);
        prob[start] = 1;
        while (!que.empty()) {
            auto [pr, node] = que.top();
            que.pop();
            if (pr < prob[node]) {
                continue;
            }
            for (auto& [prNext, nodeNext] : graph[node]) {
                if (prob[nodeNext] < prob[node] * prNext) {
                    prob[nodeNext] = prob[node] * prNext;
                    que.emplace(prob[nodeNext], nodeNext);
                }
            }
        }
        return prob[end];
    }
};
// @lc code=end

