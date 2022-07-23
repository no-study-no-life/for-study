/*
 * @lc app=leetcode.cn id=1184 lang=c
 *
 * [1184] 公交站间的距离
 */

// @lc code=start


int distanceBetweenBusStops(int* distance, int distanceSize, int start, int destination){
    if(start == destination)return 0;
    int stepl = 0, stepr = 0, curl = destination, curr = start;
    while(curr != destination){
        stepr += distance[curr];
        curr = (curr + 1) % distanceSize;
    }
    while(curl != start){
        stepl += distance[curl];
        curl = (curl + 1) % distanceSize;
    }
    return stepl < stepr ? stepl : stepr;
}
// @lc code=end

