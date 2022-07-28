/*
 * @lc app=leetcode.cn id=1331 lang=c
 *
 * [1331] 数组序号转换
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void adjustMaxHeap(int* arr, int* pos, int size, int k){
    int cur = arr[pos[k]], idx = pos[k];
    for(int i = 2 * k + 1; i < size; i = i * 2 + 1){
        if(i + 1 < size && arr[pos[i + 1]] > arr[pos[i]])++i;
        if(cur < arr[pos[i]]){
            pos[k] = pos[i];
            k = i;
        }else break;
    }
    pos[k] = idx;
}

int* arrayRankTransform(int* arr, int arrSize, int* returnSize){
    *returnSize = arrSize;
    if(arrSize == 0)return arr;
    // 排序 + 一遍遍历
    int* index = (int*)malloc(sizeof(int) * arrSize);
    int* ans = (int*)malloc(sizeof(int) * arrSize);
    int cur = 1;
    *returnSize = arrSize;
    if(arrSize == 1){
        ans[0] = 1;
        return ans;
    }
    for(int i = 0; i < arrSize; ++i){
        index[i] = i;
    }
    for(int i = arrSize / 2 - 1; i >= 0; --i){
        adjustMaxHeap(arr, index, arrSize, i);
    }
    for(int i = 0; i < arrSize - 1; ++i){
        index[arrSize - i - 1] ^= index[0];
        index[0] ^= index[arrSize - i - 1];
        index[arrSize - i - 1] ^= index[0];
        adjustMaxHeap(arr, index, arrSize - i - 1, 0);
    }
    ans[index[0]] = 1;
    for(int i = 1; i < arrSize; ++i){
        if(arr[index[i - 1]] != arr[index[i]]){
            ++cur;
        }
        ans[index[i]] = cur;
    }
    return ans;
}
// @lc code=end

