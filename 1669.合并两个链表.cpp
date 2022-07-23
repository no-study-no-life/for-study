/*
 * @lc app=leetcode.cn id=1669 lang=cpp
 *
 * [1669] 合并两个链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // 分别找到待插入位置的前一个节点;
        // 将新节点介入即可;
        ListNode *p1 = list1, *p2 = list1, *p3 = list2;
        for(int i = a; i <= b; ++i){
            p2 = p2 -> next;
        }
        for(int i = 0; i < a - 1; ++i){
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        while(p3 -> next){
            p3 = p3 -> next;
        }
        p1 -> next = list2;
        p3 -> next = p2 -> next;
        p2 -> next = nullptr;
        return list1;
    }
};
// @lc code=end

