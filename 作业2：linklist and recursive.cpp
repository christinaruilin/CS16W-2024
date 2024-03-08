#include <iostream>
using namespace std;

/**********************链表与指针练习题*********************************/

// single linkedlist structure
struct ListNode {
	int val;
	ListNode *next;
};
 
/*1. 给你一个链表，删除链表的倒数第k个结点，并且返回链表的头结点。
     input: 1 2 3 4 5
     k = 3
     output: 1 2 4 5
*/

ListNode* removeNthFromEnd(ListNode* head, int n) { //其实listnode也可以进行遍历  这种倒数的话就可以通过正书的来做 然后记录一下长度和位置
   //相当于就是把倒数的变成正着数的这样就可以了 然后就调整一下顺序 然后记录一下linkedlist的长度
   ListNode* temp= head;
        int len=0;
        while(temp!=nullptr){
            len++;
            temp=temp->next;
        }

        temp=head;
        ListNode* prev= nullptr;
        int pos= len-n;
        if(pos==0){
            return head->next;
        }
       for(int i=0; i <pos;i++){
           prev=temp;
           temp=temp->next;
       }
       prev->next=temp->next;
       delete temp;
        return head;
    }
       


/*2. 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
    input: 1 2 2 3 3 3 4
    ouput: 1 2 3 4
*/
ListNode* deleteDuplicates(ListNode* head) {
    if(head==nullptr|| head->next==nullptr){
        return head;
    }
    ListNode* p1= head;
    ListNode* prev=nullptr;

    while(p1!=nullptr && p1->next!=nullptr){
        if(p1->val==p1->next->val){
            ListNode* temp= p1->next;
            p1->next=temp->next;
            delete temp;
        }
        else{
            prev=p1;
            p1=p1->next;
        }
    }
    return head;
}

/*3. 将两个升序链表合并为一个新的升序链表并返回。
     新链表是通过拼接给定的两个链表的所有节点组成的。（不允许新建链表。）
     input: 
        list1 = 1,3,5,7,8,9
        list2 = 2,4,6
     ouput: 1 2 3 4 5 6 7 8 9
*/
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    
    if(list1==NULL|| list2==NULL){
            return list1? list1: list2;
        }
        if(list1->val< list2->val){
            list1->next= mergeTwoLists(list1->next,list2);
            return list1;
        }
        else{
            list2->next=mergeTwoLists(list1, list2->next);
            return list2;
        }
    }


/*4. 从尾到头打印单向链表
    input: 1 2 3 4 
    output: 4 3 2 1
*/
void linkListReversePrint(ListNode* head) {
    ListNode* temp1=nullptr;
    ListNode* temp2=nullptr;
    
    while(head!=nullptr){
        temp1=head->next;
        head->next=temp2;
        temp2=head;
        head=temp1;
    }
    cout << temp2 << " ";
    cout<< endl;


}

/*5. 现有一链表的头指针 ListNode* pHead，给一定值x，编写一段代码将所有
     小于x的结点排在其余结点之前，且不能改变原来的数据顺序，
	 返回重新排列后的链表的头指针。
	 input: 5 4 1 2 
	 x = 3
	 output: 1 2 5 4
*/
ListNode* partition(ListNode* pHead, int x) {
   
ListNode* smallest= pHead;
ListNode* temp=pHead;
ListNode* prev=nullptr;
while(temp!=nullptr){
    if(smallest->val>temp->val){
        prev=smallest;
        smallest=temp;
    }
    
    temp=temp->next;

}
if(smallest->val>=x){
    return pHead;
}
else{
    ListNode* newNode=new ListNode{smallest->val,nullptr};
    if(prev==nullptr){
        pHead=pHead->next;
        newNode->next=partition(pHead,x);
        
    }
    else{
        prev->next=smallest->next;
        delete smallest;
        newNode->next=partition(pHead,x);
    }
    return newNode;


}
return nullptr;
}




/***********************递归练习题******************************************/

/*1.有三根杆子X，Y，Z。X杆上有N个(N>1)穿孔圆盘，盘的尺寸由下到上依次变小。要求按下列规则将所有圆盘移至Y杆：
	1. 每次只能移动一个圆盘；
	2. 大盘不能叠在小盘上面
  求最少需要移动多少步？
*/
void h(int n, char x, char y, char z){
    if(n==1){
       cout<< n<< endl;
    }
    else{
         h(n-1,x,z, y);//先移走
         cout << n;
         h(n-1,y,x,z);//移动回去

    }
}

/*2.判断一个字符串是否为回文。
    回文字符串：一个字符串，从左到右读和从右到左读是完全一样的。比如"level" 、 “aaabbaaa”
*/
bool isPalindrome(string s1, int start, int end)
{
    if(start>=end){
        return true;
    }
    if(s1[start]==s1[end]){
        return isPalindrome(s1,start+1, end-1);
    }
    return false;
}

/*3.如果一个N位数所有数码的N次方的和加起来等于这个数字本身，我们把这样的数叫做广义水仙花数.
    输入一个m (m < 7) ，求出所有满足N = m的广义水仙花数。 
    以下均为广义水仙花数
    3 (153 370 371 407) 
    5 (54748 92727 93084) 
*/