#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int N;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    in>>N;
    vector<int> f;
    vector<int> res;
    int cont = 2;
    f.push_back(1);
    f.push_back(1);
    while(f[cont-1] + f[cont-2] < N) {
        f.push_back(f[cont-1] + f[cont-2]);
        cont++;
    }
    int n = N;
    cont--;
    while(cont >= 0) {
        //cout<<"F:" <<f[cont]<<endl;
        if(f[cont] <= n) {
            n = n-f[cont];
            res.push_back(1);
        } else {
            res.push_back(0);
        }
        //cout<<n<<endl;
        cont--;
    }
    for(int i=res.size()-1;i>=0;i--) out<<res[i];
    out<<endl;

    in.close();
    out.close();
    return 0;
}
