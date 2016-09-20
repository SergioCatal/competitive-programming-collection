//Lotito Francesco 100/100
#include<fstream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int N;
int v[1000002];
int vb[1000002]; //bool visitati

int main()
{
    in>>N;
    int nt=N;
    for(int i=1;i<=N;i++) in>>v[i];
    int pos=1;
    while(vb[pos]!=1&&pos<=N)
    {
        nt--; //posizioni non visitate
        vb[pos]=1; //visito la posizione
        pos=(pos+v[pos])%N+1; //nuova posizione
    }
    out<<nt<<endl;
    for(int i=1;i<=N;i++) if(vb[i]==0) out<<i<<" ";
}
