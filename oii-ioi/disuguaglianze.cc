#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N;
    in>>N;
    int m = 1;
    int M = N;
    for(int i=0;i<N-1;i++) {
        char s;
        in>>s;
        if(s=='<') out<<m++<<" ";
        else out<<M--<<" ";
    }
    out<<M<<endl;
    in.close();
    out.close();
    return 0;
}
