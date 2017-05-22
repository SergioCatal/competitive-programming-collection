#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    vector<string> v;
    int N;
    in>>N;
    for(int i=0;i<N;i++) {
        string a;
        in>>a;
        v.push_back(a);
    }
    for(int i=0;i<v[0].length();i++) {
        char t = v[0][i];
        int j;
        for(j=1;j<N;j++) {
            if(v[j][i] != t) { out<<i<<endl; break; }
        }
        if(j != N) break;
    }
    in.close();
    out.close();
    return 0;
}
