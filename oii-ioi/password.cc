#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<unordered_map>
using namespace std;
unordered_map<double, long long> m;

int main() {
    std::ios_base::sync_with_stdio (false);
    freopen("input.txt", "r", stdin); // redirects standard input
    freopen("output.txt", "w", stdout); // redirects standard output
    int N;
    long long K;
    long long sol = 0;
    cin>>N>>K;
    long long a;
    for(int i=0;i<N;i++) {
        cin>>a;
        m[a]++;
    }

    //cout<<"K: "<<K<<endl;
    for(unordered_map<double,long long>::iterator i=m.begin(); i!=m.end(); ++i) {
        //cout<<K/i->first<<endl;
        if(m.find(K/i->first) != m.end()) {
            if(K/i->first == i->first) {
                sol = sol + (i->second * ((i->second) - 1))/2;
            } else {
                sol = sol + (i->second * m[K/i->first]);
            }

            m[K/i->first] = 0;
        }
    }
    cout<<sol%1000000007<<endl;
    fclose (stdin);
    fclose (stdout);
}
