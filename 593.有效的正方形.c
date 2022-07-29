/*
 * @lc app=leetcode.cn id=593 lang=c
 *
 * [593] 有效的正方形
 */

// @lc code=start

# define MIN(x, y) (((x) < (y)) ? (x) : (y))
# define MAX(x, y) (((x) < (y)) ? (y) : (x))

int getDistance(int* p1, int* p2){
    return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
}

bool validSquare(int* p1, int p1Size, int* p2, int p2Size, int* p3, int p3Size, int* p4, int p4Size){
    int d1 = getDistance(p1, p2), d2 = getDistance(p1, p3), d3 = getDistance(p1, p4);
    int minval = MIN(d1, d2), maxval = MAX(d1, d2);
    minval = MIN(minval, d3); maxval = MAX(maxval, d3);
    if(2 * minval != maxval || minval == 0)return false;
    if(d1 == maxval){
        if(getDistance(p3, p4) != maxval)return false;
        return (minval == d2 && d2 == d3 && d2 == getDistance(p2, p3) && d2 == getDistance(p2, p4));
    }else if(d2 == maxval){
        if(getDistance(p2, p4) != maxval)return false;
        return (minval == d1 && d1 == d3 && d1 == getDistance(p3, p4) && d1 == getDistance(p2, p3));
    }else{
        if(getDistance(p2, p3) != maxval)return false;
        return (minval == d1 && d1 == d2 && d1 == getDistance(p2, p4) && d1 == getDistance(p3, p4));
    }

}
// @lc code=end

