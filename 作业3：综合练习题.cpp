#include <iostream>
using namespace std;
#include <iomanip>


/**
1.给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
  要求使用二分查找的方法
*/

// 返回类型是整数，结果只保留整数部分 ，小数部分被舍去 。
int sqrt_1(int x) {
  if (x == 0 || x == 1) {
        return x;
    }
    
    int start = 1;
    int end = x;
    int result = 0;
    
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (mid <= x / mid) {
            start = mid + 1;
            result = mid;
        } else {
            end = mid - 1;
        }
    }
    
    return result;




}

int sqrt_1(int x, int start, int end){ //using recursive
  if(x==0 || x==1){
    return x;
  }
int mid=start+ (end-start)/2;
int srqt= x/mid;
if(srqt==mid){
  return mid;
}
else if(srqt>mid){
  return sqrt_1(x,mid+1,end);
}
else{
 return sqrt_1(x,start,mid-1);

}


}

// 返回类型是实数，结果保留小数点后2位。
double sqrt_2(int x) {
   double start=1.0;
   double end=x;
   double result=0.0;
   while(start<=end){
    double mid= start+(end-start)/2;
    if(mid<=x/mid){
      start=mid+1;
      result=mid;
    }
    else{
      end=mid-1;
    }
   }
   cout << fixed<< setprecision(2)<< result<< endl;//如果想要设置精度的话首先要包含一个头部文件 然后先cout 让这个变成两位数 然后再return返回出来
   return result;

}


/*根据如下结构，完成第2、3题*/
struct ListNode {
    int val;
    ListNode *next;
};
/**
2.给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
*/
ListNode* sortList(ListNode* head) {
  if (head == nullptr || head->next == nullptr) {
        return head;
    }
  ListNode* smallest=head;
  ListNode* p=head;
  ListNode* prev=nullptr;
  //查找最小节点
  while(p!=nullptr){
    if(p->val<smallest->val){
      prev=p; //prev是来记录前一个节点的
      smallest=p;
    }
    p=p->next;
  }
  if(prev==nullptr){
    ListNode* temp=head;
    head=head->next;
    delete temp;

  }
  else{
    ListNode* temp=smallest;
    prev->next=temp->next;
    delete temp;
  }
  ListNode* newNode= new ListNode {smallest->val, nullptr};
  newNode->next= sortList(head);
  
  return newNode;





}
/**
3.给定两个用链表表示的整数，每个节点包含一个数位。
这些数位是反向存放的，也就是个位排在链表首部。
编写函数对这两个整数求和，并用链表形式返回结果。
输入：(7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295
输出：2 -> 1 -> 9，即912
*/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

ListNode* p1=l1;
ListNode* p2= l2;
int num1=0;
int num2=0;
int m=0;
int n=0;
int i,j=0;
while(l1!=nullptr){
 ++m;
 l1=l1->next;

}
while(l2!=nullptr){
  ++n;
  l2=l2->next;
}
p1=l1;
p2=l2;

while((l1!=nullptr || l2!=nullptr) && (i<=m || j<=n)){
  num1+=l1->val * pow(10,i);
  num2+=l2->val * pow(10,j);
  l1=l1->next;
  i++;
  l2=l2->next;
  j++;


  
}
int result=num1+num2;
ListNode* newList = new ListNode {result %10, nullptr};
result=result/10;
ListNode* temp=newList;
while(result!=0){
temp->next= new ListNode {result % 10, nullptr};
result/10;
temp=temp->next;
}
return newList;
}


/**
4.设计如下单链表：
单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。
假设链表中的所有节点下标从 0 开始。

实现 MyLinkedList 类：

MyLinkedList() 初始化 MyLinkedList 对象。
int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。

*/
class MyLinkedList{
  public:
        int getIndex(int index);
        void addAtHead(int val);
        void addAtTail(int val);
        void addAtIndex(int index, int val);
        void deleteAtIndex(int index);
  private

}

/**
5. 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
输入：num1 = "12345", num2 = "11"
输出：12356
*/
string add(string num1, string num2) {
  string result="";//规定一下这个结果先为空
  int i = num1.size()-1;
  int j=num2.size()-1;
  int carry = 0;
  while(i>=0 || j>=0 || carry!=0){
    int digit1 = (i >= 0 ? num1[i--] - '0' : 0);//加法是从尾到头进行加减
        int digit2 = (j >= 0 ? num2[j--] - '0' : 0);
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;//这个表示的是进制进几位
        result = char('0' + sum % 10) + result;
    }

    return result;

  

}

/**
6. 给你一个字符数组 chars ，请使用下述算法压缩：
从一个空字符串 s 开始。对于 chars 中的每组 连续重复字符 ：
如果这一组长度为 1 ，则将字符追加到 s 中。
否则，需要向 s 追加字符，后跟这一组的长度。
压缩后得到的字符串 s 不应该直接返回 ，需要转储到字符数组 chars 中。需要注意的是，如果组长度为 10 或 10 以上，则在 chars 数组中会被拆分为多个字符。
请在 修改完输入数组后 ，返回该数组的新长度。
你必须设计并实现一个只使用常量额外空间的算法来解决此问题。
示例 1：
输入：chars = ["a","a","b","b","c","c","c"]
输出：返回 6 ，输入数组的前 6 个字符应该是：["a","2","b","2","c","3"]
解释："aa" 被 "a2" 替代。"bb" 被 "b2" 替代。"ccc" 被 "c3" 替代。
*/
int compress(vector<char>& chars) {
   vector<char> s;
   int result=0;
   if(chars.size()==1){
    s=chars;
    return 1;
   }
   else{
    int i=0;
   while(i<chars.size()){
       char cur= chars.at(i);
       
        for(int j=i; j < chars.size();j++){
          if(chars.at(i)==chars.at(j)){
            result++;
          }
          else{
            break;
          }
          
          
        }
        s.push_back(chars.at(i));
        if(result>1){
          s.push_back(result-'0');
        }
        i=i+result;
        result=0;
       
    }
    chars=s;
    return s.size();

   }
  


}

/**
7.给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
说明：解集不能包含重复的子集。
输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]


*/
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

int main(int argc, char const *argv[])
{
	
	return 0;
}