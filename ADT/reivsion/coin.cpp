#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,picked=0;
    vector<int>coinsPicked;
    cin>>n;
    int arr[]={2000,200,100,50,20,10,5,2,1};
    for(int i=0;i<9;i++){
        while(arr[i]<=n){
            n-=arr[i];
            picked++;
            coinsPicked.push_back(arr[i]);
        }
    }
    // cout<<picked;
    for(int i=0;i<coinsPicked.size();i++){
        cout<<coinsPicked[i]<<" ";
    }
}