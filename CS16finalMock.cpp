#include <iostream>
using namespace std;
#include <string>
#include <vector>

struct ListNode{
    int val;
    ListNode* next;
};
ListNode* rotateRightRecursive(ListNode* head, int k) { //this method is using recursion to solve
//however, when k is really large, this method is not effective and will be slow
//not recommend to use but it still worked 
       if(head==nullptr || head->next==nullptr ||k==0){
        return head;
       }

       ListNode* p= head;
       ListNode* prev= nullptr;
       while(p->next!=nullptr){
        prev=p;

        p=p->next;

       }
       ListNode* temp=p;
       temp->next=head;
       prev->next=nullptr;
       head=temp;
       
       head=rotateRightRecursive(head->next,k-1);
       return head;


}

ListNode* rotateRight(ListNode* head, int k){
    //this is the non recursion way to solve this
    
    if(head==nullptr || head->next==nullptr ||k==0){
        return head;
       }
    ListNode* p=head;
    ListNode* prev=nullptr;
    while(k>0){
        while(p->next!=nullptr){
            prev=p;
            p=p->next;
        }
        ListNode* temp=p;
        temp->next=head;
        head=temp;
        if(prev!=nullptr){
            prev->next=nullptr;
        }
        --k;

    }
    return head;
}

ListNode* middleNode(ListNode* head){ //find the middle node of the linkedlist
   ListNode* slow=head;
   ListNode* fast=head;

   while(fast!=nullptr && fast->next!=nullptr){
    slow=slow->next;
    fast=fast->next->next;
   }
   return slow;
}

void printCommonPart(ListNode* head1, ListNode* head2){
    ListNode* p1=head1;
    ListNode* p2=head2;
    
    if(head1==nullptr || head2==nullptr){
       cout<< "no common parts"<< endl;
    }
   else{ 
    while(p1!=nullptr && p2!=nullptr){
        if(p1->val<p2->val){
            p1=p1->next;
        }
        else if(p1->val>p2->val){
            p2=p2->next;
        }
        else{
            cout << p1->val;
            p1=p1->next;
            p2=p2->next;
        }
    }
    
   }
   cout << endl;

}

void sumTriangleNum (int A[],int n){
    int temp[n-1];
   if(n<1){
    return; //print nothing 
   }
    for(int i=0; i < n-1; i++){
        temp[i]=A[i]+A[i+1];
    }
   
   sumTriangleNum(temp,n-1);
   
   for(int i=0; i <n; i++){
    if(i==n-1){
        cout << A[i]<< " ";
    }
    else{
        cout << A[i]<< ", ";
    }
   }
   cout << endl;
    
}

int sqrt_1(int x) {// using non recursive method (binary search)

if(x==1 || x==0){
    return x;
}
  int start=1;
  int end=x;
  int result=0;

  while(start < end){
    int mid=start+(end-start)/2;
    if(mid<=x/mid){
        start=start+1;
        result=mid;
    }
    else{
        end=mid-1;
    }
  }
  return result;

}

int sqrt_1Recursive(int x, int start, int end) {
    if(x==0 || x==1){
        return x;
    }
    int mid= start+(end-start)/2;
    int sqrt=x/mid;
    if(sqrt==mid){
        return mid;

    }
    else if(sqrt>mid){
        return sqrt_1Recursive(x, mid+1, end);
    }
    else{
        return sqrt_1Recursive(x, start, mid-1);
    }
    return x;

}

string add(string num1, string num2) {
string result="";
 int l1= num1.size()-1;
 int l2=num2.size()-1;
 int carry=0;

 while(l1>=0 || l2>=0 || carry !=0){
    int digit1= (l1>=0)?num1[l1--]:0;
    int digit2 =(l2>=0)?num2[l2--]:0;
    int sum=digit1+digit2+carry;
    carry=sum/10;
    result = char('0' + sum % 10) + result;

 }
 return result;

}
string minus(string num1, string num2){
    string result="";
    int l1=num1.length();
    int l2=num2.length();
    int borrow=0;
    while(l1>=0 || l2>=0 ){
        int digit1= (l1>=0)?num1[l1--]:0;
        int digit2 =(l2>=0)?num2[l2--]:0;
        int diff= digit1-digit2-borrow;
        if(diff<0){
            diff+=10;
            borrow==1;
        }
       else{
        borrow=0;
       }
       result = char('0' + diff) + result;
        
   
}
 return result;
}

int fib(int n){
    if(n==0){
        return 0;
    }
    if(n==1 || n==2){
        return 1;
    }
    return fib(n-2)+fib(n-1);


}

ListNode* getIntersectNode(ListNode* head1, ListNode* head2){
    
    if(head1==nullptr || head2==nullptr){
        return nullptr;
    }
    
    
    while(head2){
       ListNode* temp=head1;
       while(temp){
        if(temp==head2){
            return head2;
        }
        temp=temp->next;
       }
       head2=head2->next;
    }
    return nullptr;


}

ListNode* deleteDuplicates(ListNode* head) {
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    ListNode* p=head;
    
    while(p->next!=nullptr && p!=nullptr){
        if(p->val==p->next->val){
           ListNode* temp=p->next;
           p->next=temp->next;
           delete temp;  
        }
        else{
            p=p->next;
        }
      
    }
    return head;
}

void allPowerSet(vector<int> numList, vector<int> remain){
  
  if(numList.empty()){
    for(int i=0; i < remain.size();i++){
      cout << remain.at(i);
    }
    cout << endl;
  }
  else{
    for(int i=0; i < numList.size(); i++){
      int temp=numList.at(i);
      remain.push_back(temp);
      for(int j=0; j < remain.size();i++){
        cout << remain.at(j);
      }
      cout << endl;
      numList.erase(numList.begin()+i);
      allPowerSet(numList,remain);
      numList.insert(numList.begin() + i, temp);
      remain.pop_back();

    }
  }
  
}

class ZooAnimal  
{
private:
	char *name;
	int cageNumber;
	int weightDate;
	int weight;
public:
   ZooAnimal(char *who, int cage, int date,int weight){
	name=new char[20];//because it asks to initialize to 20 characters 
	strcpy(name, who);
	cageNumber=cage;
	weightDate=date;
	weight=weight;
   }
   ZooAnimal(){
	name="Nameless";
	cageNumber=9999;
	weightDate=101;
	weight=100;
   }
    
};










