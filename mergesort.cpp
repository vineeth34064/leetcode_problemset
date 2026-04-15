#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&arr,int low,int mid,int high){
    vector<int>temp;
    int left = low;
    int right = mid+1;

    while(left <= mid && right <= high){
        if(arr[left] < arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }

        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }
    }
    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
}

void mergesort(vector<int>&arr,int low,int high){
    if(low >= high)return ;

    int mid = low +(high-low)/2;

    mergesort(arr,low,mid);
    mergesort(arr,high,mid+1);
    merge(arr,low,mid,high); 
}


int main(){
    vector<int>arr;
    for(int i = 0; i < arr.size(); i++){
        arr.push_back(rand()%100);
    }
    mergesort(arr,0,arr.size()-1);
    for(int i:arr){
        cout<<i<<" ";
    }
}