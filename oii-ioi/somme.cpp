#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N;
    in >> N;
    priority_queue<int> q;
    for(int i=0;i<N;i++) {
        int a;
        in>>a;
        q.push(-1 * a);
    }
    int res = 0;
    int ad = 0;
    int cont = 0;
    bool ok = false;
    while(!q.empty()) {
        if(q.size() == 1 && ok) {
            out<<res<<endl;
            q.pop();
        }
        else {
            ad = ad - q.top();
            q.pop();
            cont++;
            if(cont == 2) {
                res += ad;
                cout<<ad<<endl;
                //cout<<res<<endl;
                cont = 0;
                q.push(-1 * ad);
                ad = 0;
                if(q.size() == 1) ok = true;
            }
        }
    }
    in.close();
    out.close();
    return 0;
}



