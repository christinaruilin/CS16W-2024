#include <iostream>
using namespace std;
#include <vector>

void permutationVectors(vector<int> &curr,vector<int>& remain ){
    if(remain.empty()){
        for(int i=0; i < curr.size();i++){//base case直接打印出来
           cout<< curr.at(i);


        }
      cout << endl;
        
    }
    else{//说明remain里面还有东西所以要继续
    for(int i=0; i < remain.size();i++){
        int temp=remain.at(i);
        curr.push_back(temp);
        remain.erase(remain.begin()+i);
        permutationVectors(curr,remain);
        curr.pop_back();
        remain.insert(remain.begin()+i, temp);

    }

    }
}


int main(){
    return 0;

}