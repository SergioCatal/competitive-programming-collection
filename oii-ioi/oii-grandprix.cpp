//Lotito Francesco, 5/5
#include<fstream>
#include<algorithm>
using namespace std;
int N, M;
ifstream fin("input.txt");
ofstream fout("output.txt");
int v[31];

int main()
{
    fin>>N>>M;
    for(int i=1;i<=N;i++)
    {
            int a;
            fin>>a;
            v[a]=i;
    }
    for(int i=0;i<M;i++)
    {
            int a,b;
            fin>>a>>b;
            v[a]--;
            v[b]++;
    }
    for(int i=1;i<=N;i++)if(v[i]==1)fout<<i<<endl;
    fin.close();
    fout.close();    
}
