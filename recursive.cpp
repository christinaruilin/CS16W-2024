#include <iostream>
using namespace std;
#include <string>
//在做recursive的题的时候特别是遇到问输出什么的时候一定要有big picture 不要把自己纠结到recursive方法里面
//这样就把自己绕迷糊了一定要有big picture知道是干什么的就不要钻进去研究recursive里面干了什么

//need to have base case : the easiest condition 
//each result is based on the previous one  
//when think about it, think it as another seperate function 
struct ListNode{
    int value;
    ListNode* next;
};
int fib(int n) {
    if(n=0){
        return 0;

    }
    else if(n==1 || n==2){
        return 1;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
        
    }

  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) { // 如果遇到这种多重判断的时候其实可以用一行就把这个写清楚的就是直接用 list1? list1: list2; 这种方式来表达
        if(list1==nullptr && list2!=nullptr){
            return list2;
        }
        if(list1!=nullptr && list2==nullptr){
            return list1;
        }
        if(list1==nullptr && list2==nullptr){
            return nullptr;
        }
        else{
            if(list1->value<=list2->value){
                ListNode* temp= list1->next;
                list1->next=list2;
                list2->next= mergeTwoLists(list2->next,temp);
                return list1;
            }
            else{
                ListNode* temp=list2->next;
                list2->next=list1;
                list1->next= mergeTwoLists(list1->next, temp);
                return list2;

            }

        }
        return nullptr;
        
    }

     ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) 
        return nullptr;
        head->next = removeElements(head->next, val);
        return head->value == val ? head->next : head;
    }

     bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
        return true;
    }
    
        ListNode* p1=head;
        ListNode* head2=head;
        ListNode* temp=nullptr;
        while(head2!=nullptr){
            p1=head2->next;
            head2->next=temp;
            temp=head2;
            head2=p1;
            
        }
        ListNode* origin= head;
        while(temp!=nullptr && origin!=nullptr){
            if(temp->value!=origin->value){
                return false;
            }
            else{
            temp=temp->next;
            origin=origin->next;
            }
        }
        return true;  
        
    }
//这个题就是说把相邻的两个node进行一下swap
    ListNode* swapPairs(ListNode* head) {
       if(head==nullptr || head->next== nullptr){
           return head;
       } 
     
      ListNode* p2=head->next;
      head->next= swapPairs(head->next->next);
      p2->next=head;
      return p2;
    }

string reverseString(string str){
    if(str.size()<=1){
        return str;
    }
    
    return reverseString(str.substr(1))+ str[0]; //str. substr(1)的意思就是从第二个字符到最末尾的整个字符串
    //这个用recursive的意思就是说从big picture来看 最后一个和第一个进行swap 那这个recursive就是做的这个工作 也就是说每次都把第一个加到最后

    }
string decimalTobinary(int n){
    

    if(n==0){
        return "";
    }
    
    return decimalTobinary(n/2) + to_string(n%2); //需要转换成string1类型的参数
    //这个就需要想这个的结果应该是什么 是不是最后一个余数在第一个 第一个余数在最后一个 
}

int countZeros(int n){ //这个方法是让操作一个数里面有几个0 
    if(n<10){
    return (n==0)? 1:0;}

    int count=(n%10==0)?1:0;

    return count + countZeros(n/10);
    
}
//十进制转十六进制的具体操作方法就是这个数字除以16 然后取余数 余数从下往上
string decToHex(int decimal){ //因为hex的长度也比较长而且还有一些字符串所以返回类型要是string才可以
    if(decimal==0){
        return "0";
    }
    
 string hex=" ";//这个就是规定一个结果然后最后就是往结果里面填东西
 while(decimal>0){
   int remainder= decimal %16;
   if(remainder <10){
    hex=char('0'+remainder)+hex; //这个就是把结果加上去 
   }
   else{
    hex=char('A'+remainder-10)+hex; //关于十六进制的char的转换
   }
   decimal/=16;
 }
 return hex;
}

bool isSorted(const vector<int>& vec, int index=0){
    if(index=vec.size()-1 || vec.size()==0){
        return true;
    }
    if(vec[index]<=vec[index+1]){
        return isSorted(vec,index+1);
    }
    return false;
}
int binarySearch(const vector<int> & vec, int target, int low, int high){
    int mid =(low+high)/2;
    if(low<=high){
        if(vec[mid]==target){
            return mid;
        }
        else if(vec[mid]<target){
            return binarySearch(vec, target,mid+1, high );
        }
        else{
            return binarySearch(vec, target, low, mid-1);
        }
    }
}
string hecToDec2(int decimal){ //用recursive的方法写
  if(decimal==0){
    return "";
  }
  string hex= hecToDec2(decimal/16);
  int remainder = decimal%16;
  if(remainder<10){
    hex+= char('0'+remainder);
  }
  else{
    hex+=char('A'+remainder-10);
  }
  return hex;
}
//Print all Palindromic Partitions of a String using Backtracking
bool isPalindromic(string& s1){
    int i=0;
    int j=s1.size()-1;
    while(i<j){
        if(s1[i]!=s1[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void printAll(vector<vector<string>> & res, string &s, int index, vector<string> & cur){
  if(index==s.size()){
    res.push_back(cur);
    return;
  }
  string t;
  for(int i=index; i <s.size();i++){
    t.push_back(s[i]);
  }
  if(isPalindromic(t)){
    cur.push_back(t);
    printAll(res,s,index+1,cur);
    cur.pop_back();
  }
}

ListNode* deleteKthNode(ListNode* head,int k){
    if(head==nullptr){
        return nullptr;
    }
    if(k==1 && head->next==nullptr){
        return NULL;
    }  
    
    head->next=deleteKthNode(head->next,k-1);
    if(k==1){
      ListNode* temp=head->next;
      delete head;
      return temp;
    }


   
    
     return head;
    
}

ListNode* deleteKthNodeNonRecursive(ListNode* head,int k){
    ListNode* p=head;
    ListNode* prev=nullptr;
    int count=1;
    if(k==count){
        head=head->next;
        delete p;
        return head;
    }

    while(count!=k){
        prev=p;
        p=p->next;
        count++;
    }
    prev->next=p->next;
    delete p;
    return head;
}
void sumTriangleNum (int A[],int n) {//n代表的是这个array的长度以及高度
 if(n<=1){
    return;
 }
 int temp[n-1];
 for(int i=0; i <n-1; i++){
    int x=A[i]+A[i+1];
    temp[i]=x;
 } //这个相当于把第二层给求出来了
 //因为递归要告诉具体要干什么事情在递归前面
 sumTriangleNum(temp,n-1);
 
 for (int i = 0; i < n ; i++)
        {
            if(i == n - 1)
                cout << A[i] << " "; //最后一个是打印空格 然后其余的是打印逗号
            else
            cout << A[i] << ", ";
        }
                   
        cout << endl;


}
void printAll(int k, int n, int arr[], int& len){
    if(len==k){
        for(int i=0; i < k; i++){
            cout << arr[i];
        }
        cout << endl;
    }
    else{
        int i= (len==0)? 1: arr[len-1]+1;
        len++;
        while(i<=n){
            arr[len-1]=i;
            printAll(n,k,arr,len);
            i++

        }

    }


}






int main(){
    string s= "hello";
    cout<< sizeof(s)<< endl;

    return 0;
}


