#include <fstream>
#include <cstring>
#include <cstdlib>
#define MAX_LG_SIR 33
#define MAX_LG_CUV 11
#define MAX_CUV 3
#define SECUNDE_PE_MINUT 60
#define SECUNDE_PE_ORA 3600
#define ORE_PE_ZI 24
using namespace std;
unsigned long long oraTimer;
unsigned zile, ore, minute, secunde;
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
    if (ore < 10)
	    fout << 0 << ore;
    else
	    fout << ore;
    fout << ':';
    if (minute < 10)
	    fout << 0 << minute;
    else
	    fout << minute;
    fout << ':';
    if (secunde < 10)
	    fout << 0 << secunde;
    else
	    fout << secunde;
    if (zile > 0)
	    fout << '+' << zile;
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
            return atoll(parteaIntreaga[0]);
        case 2:
            return SECUNDE_PE_MINUT * atoll(parteaIntreaga[0])
                + atoll(parteaIntreaga[1]);
        case 3:
            return SECUNDE_PE_ORA * atoll(parteaIntreaga[0])
                + SECUNDE_PE_MINUT * atoll(parteaIntreaga[1])
                + atoll(parteaIntreaga[2]);
        default:
            return 0;
    }
}
void determinaOraLaCareSemnalulSonorVaFiEmis()
{
    zile = oraTimer / SECUNDE_PE_ORA / ORE_PE_ZI;
    ore = oraTimer / SECUNDE_PE_ORA % ORE_PE_ZI;
    minute = oraTimer % SECUNDE_PE_ORA / SECUNDE_PE_MINUT;
    secunde = oraTimer % SECUNDE_PE_ORA % SECUNDE_PE_MINUT;
}
void citesteDateleDeIntrare()
{
    ifstream fin("timer.in");
    char oraCurenta[MAX_LG_SIR], timpDeAsteptare[MAX_LG_SIR];
    fin >> oraCurenta;
    fin >> timpDeAsteptare;
    oraTimer = convertesteInSecunde(oraCurenta)
               + convertesteInSecunde(timpDeAsteptare);
}
