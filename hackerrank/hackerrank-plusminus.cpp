#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    double p=0, ne=0, z=0;
    for(int i=0;i<n;i++) {
        if(arr[i]==0)z++;
        else if(arr[i]>0)p++;
        else ne++;
    }
    p=p/n;
    z=z/n;
    ne=ne/n;
    cout<<p<<endl<<ne<<endl<<z;
    return 0;
}
