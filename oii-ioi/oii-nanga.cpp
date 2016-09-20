//Lotito Francesco, 5/5
#include<fstream>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
int v[100001];
int N;

int main()
{
    v[5000]=1;
    fin>>N;
    int altezza=5000;
    for(int i=0;i<N;i++)
    {
            int ril;
            fin>>ril;
            altezza+=ril;
            v[altezza]++;
    }
    int max=0;
    int pos=-1;
    for(int i=0;i<100001;i++)if(v[i]>max){ max=v[i]; pos=i; }
    fout<<pos;
    fin.close();
    fout.close();
}
