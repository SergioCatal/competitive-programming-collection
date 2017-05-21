#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

bool isPrime(int N) {
    if(N==1 || N % 2 == 0) return false;
    if(N==2) return true;
    for(int i=3; i<int(sqrt(N))+1; i+=2) {
        if(N % i == 0) return false;
    }
    return true;
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N;
    in>>N;
    bool ok = false;
    if(isPrime(N)) {
        out<<-1<<endl;
    } else {
        for(int i = 2; i<int(sqrt(N))+1; i++) {
            if(N % i == 0 && isPrime(N/i) && isPrime(i)) {
                ok = true;
                out<<i<<" "<<N/i<<endl;
                break;
            }
        }
    }
    if(!ok) out<<-1<<endl;
    in.close();
    out.close();
    return 0;
}
