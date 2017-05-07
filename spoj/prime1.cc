#include<iostream>
#include<cmath>
using namespace std;

bool isprime(int n) {
    if(n<2) return false;
    if(n==2 || n == 3) return true;
    if(n%2 == 0) return false;

    for(int i=3; i < sqrt(n)+1; i+=2) {
        if(n%i == 0) return false;
    }
    return true;
}

int main() {
    int T, n, m;
    cin>>T;
    for(int t=0;t<T;t++) {
        cin>>n>>m;
        for(int i=n;i<=m;i++) {
            if(isprime(i))cout<<i<<endl;
        }
    }
    return 0;
}
