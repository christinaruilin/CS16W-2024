#include <iostream>
using namespace std;

struct ListNode{
    int value;
    ListNode* next;
};

ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || (head->next==nullptr)|| k==0){
            return head;
        }
        
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(k>0){
        while(temp->next!=nullptr){
            prev=temp;
            temp=temp->next;
        }
        ListNode* p= temp;
        p->next=head;
        head=p;
        if(prev!=nullptr){
        prev->next=nullptr;}
       --k;


        }
        return head;
       
        
    }

    ListNode* middleNode(ListNode* head) { //找中间的节点 leetcode 876
    //使用了两个节点一个移动快一个移动慢 那当快的到达终点的时候 满的刚好在一半的位置
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}