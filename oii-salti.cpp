//Lotito Francesco 100/100
#include <fstream>
using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int D;
    in>>D;
    int cont=1;
    while(D!=1)
    {
        if(D%2==1) cont++;
        D/=2;
    }
    out<<cont;
}
