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

// 这个题目要求实现一个函数，输入是一个单链表，要求删除其中所有的偶数节点。偶数节点是指节点的值为偶数的节点。

ListNode* deleteEven(ListNode* head){
  
   if(head==nullptr|| ((head->val)%2==0 && head->next==nullptr)){
    return nullptr;
   }

    head->next=deleteEven(head->next);
    if((head->value)%2==0){
        ListNode* temp=head->next;
        delete head;
        return temp;


    }
    return head;

   
}

ListNode* deleteKthNodeFromBack(ListNode* head, int k){ //this function is aimed to delete the kth node from the back
   if(head==nullptr || (head->next==nullptr && k==1)){
    return nullptr;
   }
   ListNode* p= head;
   int size=0;
   while(p!=nullptr){
    size++;
    p=p->next;
   }
   head->next=deleteKthNodeFromBack(head->next,k ); //为什么在这个地方k的值没有改变
   //首先可以这样思考一下 就是把recursion当作一个遍历的过程 每次遍历的过程当中整个linkedlist的size
   //都在变小 但是k的值没有发生任何变化 k代表的是倒数第几个节点 那保持k不动 如果说现在的linkedlist的长度
   //等于k的值了 那自然就是要删除的那个节点 那在下面直接删除就可以
   //如何考虑：我觉得如果是倒数往前删除节点的话就需要让k不要动 但是改变linkedlist的长度当k的值等于当前
   //linkedlist值的时候 那就是要删除的节点 就可以进行删除了
   if(k==size){
    ListNode* temp=head;
    head=head->next;
    delete temp;
    return head;
   }
   return head;


}

ListNode* deleteMiddle (ListNode* head, int size){//delete the middle node of the linkedlist
   if(size<=1){
      return head;
   }
    
    
    
    if(size%2==0){
        int mid=size/2;
        head->next=deleteMiddle(head->next, size-1);
        if(mid==size){
            ListNode* temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        return head;
         
    }
    else{
        int mid=size/2+1;
        head->next=deleteMiddle(head->next, size-1);
        if(mid==size){
            ListNode* temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        return head;

    }
    return head;
}

ListNode* deleteMiddle(ListNode* head) {  //这个题如果不用recursive做的话那就可以直接找到middle
//用两个节点 一个快节点 一个慢节点 然后直接找到那个中间节点直接删除就可以了
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=head;
        while(fast!=NULL && fast->next!=NULL){
            if(prev!=NULL){
                prev=slow;
            }
            slow=slow->next;
            fast=fast->next->next;
        }
        while(prev->next!=slow  && slow!=NULL){
            prev=prev->next;
        }
        prev->next=slow->next;
        return head;
    }