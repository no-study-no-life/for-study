/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 */

// @lc code=start
class MyCircularQueue {
    // front: 第一个非空位置
    // tail: 第一个空位置
    // front == tail表示队列为空
    // tail + 1 == front表示为满;
    // 即用一个空位区分空与满;
    int *arr, front, tail, size;
public:
    MyCircularQueue(int k) {
        size = k + 1;
        front = 0;
        tail = 0;
        arr = new int[size];
    }

    ~MyCircularQueue(){ delete[] arr; }
    
    bool enQueue(int value) {
        if((tail + 1) % size == front)return false;
        arr[tail++] = value;
        tail %= size;
        return true;
    }
    
    bool deQueue() {
        if(front == tail)return false;
        front = (front + 1) % size;
        return true;
    }
    
    int Front() {
        if(front == tail)return -1;
        return arr[front];
    }
    
    int Rear() {
        if(front == tail)return -1;
        return arr[(tail - 1 + size) % size];
    }
    
    bool isEmpty() {
        return front == tail;
    }
    
    bool isFull() {
        return (tail + 1) % size == front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

