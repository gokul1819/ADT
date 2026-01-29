#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

struct Activity{
    int start,end,index;
};
struct compare{
    bool operator()(Activity a,Activity b){
        return a.end<b.end;  //fails-> swap of values will happen
    }
};
int main(){
    int n;
    cin>>n;
    vector<Activity>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].start>>arr[i].end;
        arr[i].index=i+1;
    }
    // sort(arr.begin(),arr.end());
    // sort(arr.begin(),arr.end(),compare());
    
    vector<Activity>result;
    int currentTime=arr[0].end;
    
    result.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(currentTime<=arr[i].start){
            result.push_back(arr[i]);
            currentTime=arr[i].end;
        }
    }
    
    cout<<"Selected activities are:\n";
    for(int i=0;i<result.size();i++){
        cout<<"("<<result[i].start<<","<<result[i].end<<") ";
    }
}