#include<iostream>
#include<vector>

using namespace std;
int  trap(vector<int>&height){
    int n = height.size();
    int prev [n];
    prev[0] = -1;
    int max = height[0];
    for(int i = 1; i<n; i++){
        prev[i] = max;
        if(max<height[i]) max = height[i];
    }
    // next greatest element array
    int next [n];
    next[n-1] = -1;
    max = height[n-1];
    for(int i = n-2 ; i>0; i--){
        next[i] = max;
    }
    // minimun array 
    int mini[n];
    for(int i=0; i<n; i++){
        mini[i] = min (prev[i],next[i]);
    }
    // calculating water
    int water = 0 ; 
    for(int i=0; i<n-1; i++){
        if(height[i]<mini[i]){
            water += (mini[i]-height[i]);
        }
    }
    return water;
}

int main (){
    vector<int>v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(2);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    
    for(int i= 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    
    cout<<"\n";
    
}
trap(v);
for(int i= 0; i<v.size(); i++){
    cout<<v[i]<<" ";
}
}