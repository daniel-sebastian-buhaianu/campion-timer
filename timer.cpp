#include <fstream>
#include <cstring>
#include <cstdlib>
#define MAX_LG_SIR 33
#define MAX_LG_CUV 11
#define MAX_CUV 3
#define SECUNDE_PE_MINUT 60
#define SECUNDE_PE_ORA 3600
using namespace std;
unsigned long long oraTimer, ore, minute, secunde;
void citesteDateleDeIntrare();
void determinaOraLaCareSemnalulSonorVaFiEmis();
void afiseazaDateleDeIesire();
int main()
{
    citesteDateleDeIntrare();
    determinaOraLaCareSemnalulSonorVaFiEmis();
    afiseazaDateleDeIesire();
    return 0;
}
void afiseazaDateleDeIesire()
{
    ofstream fout("timer.out");
    fout << oraTimer << endl;
    fout << ore << ' ' << minute << ' ' << secunde <<endl;
    fout.close();
}
unsigned long long convertesteInSecunde(char sir[MAX_LG_SIR])
{
    char parteaIntreaga[MAX_CUV][MAX_LG_CUV], *p;
    int nr = 0;
    p = strtok(sir, ":");
    while (p)
    {
        strcpy(parteaIntreaga[nr], p);
        nr++;
        p = strtok(NULL, ":");
    }
    switch (nr)
    {
        case 1:
            return atoi(parteaIntreaga[0]);
        case 2:
            return SECUNDE_PE_MINUT*atoi(parteaIntreaga[0])
                + atoi(parteaIntreaga[1]);
        case 3:
            return SECUNDE_PE_ORA*atoi(parteaIntreaga[0])
                + SECUNDE_PE_MINUT*atoi(parteaIntreaga[1])
                + atoi(parteaIntreaga[2]);
        default:
            return 0;
    }
}
void determinaOraLaCareSemnalulSonorVaFiEmis()
{
    ore = oraTimer/SECUNDE_PE_ORA;
    minute = (oraTimer%SECUNDE_PE_ORA)/SECUNDE_PE_MINUT;
    secunde = (oraTimer%SECUNDE_PE_ORA)%SECUNDE_PE_MINUT;
    // TODO
}
void citesteDateleDeIntrare()
{
    ifstream fin("timer.in");
    char oraCurenta[MAX_LG_SIR], timpDeAsteptare[MAX_LG_SIR];
    fin >> oraCurenta;
    fin >> timpDeAsteptare;
    oraTimer = convertesteInSecunde(oraCurenta) + convertesteInSecunde(timpDeAsteptare);
}
