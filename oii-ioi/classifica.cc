#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N;
    int m = 0;
    int s = 0;
    int v[21];
    in>>N;
    for(int i=0;i<N*(N-1)/2;i++) {
        int a,b,c,d;
        in>>a>>b>>c>>d;
        if(c == d) {
            v[a]++;
            v[b]++;
        }
        else if(c < d) {
            v[b]+=3;
        } else {
            v[a]+=3;
        }
        if(v[a]>=m) {
            if(v[a] > m) {m=v[a]; s=a;}
            else {
                if(v[a] == m && a < s) s=a;
            }
        }
        if(v[b]>=m) {
            if(v[b] > m) {m=v[b]; s=b;}
            else {
                if(v[b] == m && b < s) s=b;
            }
        }
        if(v[b]>=m) { m=v[b]; s=b; }
    }
    out<<s<<" "<<m<<endl;
    in.close();
    out.close();
    return 0;
}
