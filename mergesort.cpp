#include <iostream>
# include <vector>

using namespace std;

void merge(vector<int>& arr,int l, int m,int h){
    int n1 =  m - l + 1;
    int n2 = h - m;
    //cout<<"enter merge"<<endl;
    int low[n1+1];
    int high[n2+1];
    for (int i =0; i<n1; ++i){
        low[i] = arr[l+i];
    }
    for (int i =0; i<n2; ++i){
        high[i] = arr[m+i+1];
    }
    low[n1] = 999;
    high[n2] = 999;
    int i =0;
    int j = 0;

    for (int k =l;k <= h; ++k){
        if (low[i] <= high[j]){
            arr[k] = low[i];
            ++i;
        }
        else{
            arr[k] = high[j];
            ++j;
        } 

    }
}

void mergesort(vector<int>& arr, int l, int h){
    
    if (l<h){
        
        int m = (l+h)/2;
        //cout<<"insider sort"<<l<<h<<m<<endl;
        mergesort(arr, l,m);
        mergesort(arr,m+1, h);
        merge(arr,l,m,h);
    }
}

int main(){
    vector<int> arr = {7, 9, 3, 77, 23, 98, 12,108,67};

    mergesort(arr, 0, arr.size()-1);
    for (int i =0; i < arr.size(); i++){
        cout<<arr[i]<<endl;
    }
}