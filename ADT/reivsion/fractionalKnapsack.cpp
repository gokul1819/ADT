//maximum profit

#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
struct Product{
    int val,wt;
    Product(int val,int wt){
        this->val=val; //this points the address
        this->wt=wt;
    }
};

struct compare{
    bool operator()(Product a,Product b)  {
        float r1=(float)a.val/a.wt;
        float r2=(float)b.val/b.wt;
        return r1>r2;
    }
};
int main(){
    vector<Product>arr;
    int cap;
    while(true){
        int wt,val;
        cin>>wt;
        if(wt==-1){
            break;
        }
        cin>>val;
        arr.push_back({val,wt});
        
    }
    cin>>cap;
    
    sort(arr.begin(),arr.end(),compare());
    
    // for(int i=0;i<arr.size();i++){
    //     cout<<arr[i].val<<"->"<<arr[i].wt<<endl;
    // }
    
    double maxProfit=0;
    for(int i=0;i<arr.size();i++){
        if(cap==0)break;
        if(cap>=arr[i].wt){
            cap-=arr[i].wt;
            maxProfit+=arr[i].val;
        }
        else{
            maxProfit+=(cap*((double)arr[i].val/arr[i].wt));
            cap=0;
        }
    }
    cout<<"The maximum value of the current list is:\n"<<fixed<<setprecision(2)<<maxProfit;
}