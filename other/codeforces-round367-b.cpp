#include <iostream>
using namespace std;
const int d = 100000;
int x[d];
int v[d]; //prefix sum

int main() {
    int N, Q;
    cin>>N;
    for(int i=0;i<N;i++) {
        int t;
        cin>>t;
        x[t]++;
    }
    v[0]=x[0];
    for(int i=1;i<d;i++) {
        v[i]=v[i-1]+x[i]; //prefix sum
    }
    cin>>Q;
    int sol[Q];
    for(int i=0;i<Q;i++){
        int q;
        cin>>q;
        if(q>=d)sol[i]=N;
        else sol[i]=v[q];
    }
    for(int i=0;i<Q;i++){
        cout<<sol[i]<<endl;
    }
    return 0;
}
