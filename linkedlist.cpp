#include <iostream>
using namespace std;

struct ListNode{
    int value;
    ListNode* next;
};

//在linkedlist中插入一个值
void insert(ListNode* head, int val){
    ListNode* p1= new ListNode;
    p1=head;
    ListNode* insert= new ListNode;
    insert->value=val;
    ListNode* current= nullptr;
    
    if(head==nullptr){//如果这个linkedlist是空的话怎么办
        head=insert;
        insert->next=nullptr;
    }
else{
    while(p1!=nullptr&& p1->value<val){
        current=p1;
        p1=p1->next;   
    }
    if(current==nullptr){//来判断插入的值比所有的值都要小
      insert->next=head;
      head=insert;
    }
    else{
       
        current->next=insert;
        insert->next=p1;
    }
}

    

}
//在linkedlist中清除特定的值
ListNode* clear(ListNode* head, int data){
    ListNode* p1=head;
    ListNode* prev= nullptr;
   
    while(p1!=nullptr&& p1->value==data){//删除是头部节点的情况
       ListNode* temp= p1;
       p1=p1->next;
       delete temp;//在c++当中如果删除一个节点要记得释放内存

        }
 head=p1;//更新头部节点
    
    while(p1!=nullptr){//并不是头部节点的情况 
        if(p1->value==data){
            
            ListNode* temp=p1;
            prev->next=p1->next; //这个prev是储存前一个节点的 如果删除了中间的节点可以更好的链接起来
            p1=p1->next;
            delete temp;

        }
        else{
            prev= p1; //保存前面一个节点
            p1=p1->next;
        }
    }
    return head;
    }

//反转链表
ListNode* reverseList(ListNode* pHead){
  ListNode* temp1=nullptr;
  ListNode* temp2= new ListNode;
  temp2=nullptr;
  while(pHead!=nullptr){
    temp2=pHead->next;
    pHead->next=temp1;//把以前的第一个元素现在变为null
    temp1=pHead;
    pHead=temp2;



  }
  return pHead;

}

void printCommonPart(ListNode* head1, ListNode* head2){
    ListNode* p1=head1;
    ListNode* p2=head2;

    while(p1!=nullptr && p2!=nullptr){
        if(p1->value<p2->value){
            p1=p1->next;
        
        }
        else if(p1->value>p2->value){
            p2=p2->next;
        }
        else{
            cout << p1->value<< endl;
            p1=p1->next;
            p2=p2->next;
        }

    }
}

ListNode* getIntersectNode(ListNode* head1, ListNode* head2){
    ListNode* p1= head1;
    ListNode* p2=head2;

     if(p1==nullptr || p2==nullptr){
        return nullptr;
    }

    

    while(p1!=nullptr&& p2!= nullptr){
        if(p1->value==p2->value){
            return p1;
        }
        p1=p1-> next;
        p2=p2->next;

    }
    return nullptr; 
}


bool check_cycle(ListNode* head){ //这个是判断链表中存不存在环
    ListNode*p1 = new ListNode;
    p1=head;
    ListNode* p2= new ListNode;
    p2=head;

    if(p1==nullptr || p2==nullptr){
        return false;
    }
    else{
      while(p1!=nullptr && p1->next!=nullptr && p2!=nullptr){
        
        p1=p1->next->next;
        p2=p2->next;
         
         if(p1==p2){
            return true;
         }
      }
    }
    return false;
}

ListNode* get_cycle_node(ListNode* head ){
  if(!check_cycle(head)){
    return nullptr;

  }
  else{
    ListNode*p1 = new ListNode;
    p1=head;
    ListNode* p2= new ListNode;
    p2=head;
    while(p1!=nullptr && p1->next!=nullptr && p2!=nullptr){
        
        p1=p1->next->next;
        p2=p2->next;
         
         if(p1==p2){
            return p1;
         }
      }
  }
  return nullptr;

}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {//其实有的时候可以想一想用recursive的方法去做 特别是涉及到连续的插入或者删除 就是要注意
     if(list1==NULL|| list2==NULL){
            return list1? list1: list2;
        }
        if(list1->value< list2->value){
            list1->next= mergeTwoLists(list1->next,list2);
            return list1;
        }
        else{
            list2->next=mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
    

     bool isPalindrome(ListNode* head) {
        ListNode* p1=head;
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* temp1= nullptr;
        while(p1!=nullptr){
            ListNode* temp2=nullptr;
            temp2=p1->next;
            p1->next=temp1;
            temp1=p1;
            p1=p1->next;
        }
        while(head && p1){
            if(head->value!=p1->value){
                return false;
            }
            head=head->next;
            p1=p1->next;
        }
        return true;
        
     }
    
    ListNode* findTail(ListNode* head){//寻找尾节点
        ListNode* p=head; //定义一个新的节点来遍历整个linklist
        while(p->next!=nullptr){ //当p->next != null的时候就是直接遍历到尾节点
            p=p->next;

        }
        return p;
    }
    void addEnd(ListNode* head, int value){
        ListNode* p=head;
        ListNode* newAdd= new ListNode;
        newAdd->value=value;
        while(p->next!=nullptr){
            p=p->next;
        }
        p->next=newAdd;
        newAdd->next=nullptr;

        

    }
    
    void print(ListNode* head){
        ListNode* p= head;
        while(p!=nullptr){
            cout<< p->value;
            p=p->next;

        }
        cout << endl;
    }



   





int main(){
   ListNode* head1=new ListNode;
   head1->value=1;
   head1->next=new ListNode;
   head1->next->value=3;
   head1->next->next=new ListNode;
   head1->next->next->value= 5;

  
   ListNode* head2=new ListNode;
   head2->value=5;
   head2->next=new ListNode;
   head2->next->value=8;
   head2->next->next=new ListNode;
   head2->next->next->value= 4;
   
   ListNode* newHead= mergeTwoLists(head1,head2);
    print(newHead);
    cout << endl;



   //ListNode* clearList= clear(head1,3);
    
   return 0; 

}
