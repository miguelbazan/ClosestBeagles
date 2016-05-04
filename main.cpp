#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;
#define MAX 100000

/*Analisis y Diseño de algoritmos
 Proyecto 1.B "Best Friends in BeagleTown
 Autores:
 Ricardo Licea A01280892
 Miguel Bazan A01281010
 */
//Bibliografia: made by Rajeev Agrawal, posted in Geeks For Geeks link: http://www.geeksforgeeks.org/closest-pair-of-points-onlogn-implementation/

struct punto
{
    float fX;
    float fY;
};

punto pC1,pC2;
double dDistMin=1e10;

int ordenax(const void *a,const void *b)
{
    return(((*(punto *)a).fX<(*(punto *)b).fX)?-1:1);
}

// FunciÛn que calcula la distancia entre dos puntos.
float dDist(punto a,punto b)
{
    return(sqrt((a.fX-b.fX)*(a.fX-b.fX)+(a.fY-b.fY)*(a.fY-b.fY)));
}

void busca(punto *p,int iNum)
{
    float dD;
    int iDesde,iHasta,iA,iB;
    
    if(iNum <= 1)     // Si no hay pares de puntos:
        return;   // salir.
    
    // Ordenar los puntos por la coordenada x.
    qsort(p,iNum,sizeof(punto),ordenax);
    
    // Mirar en el subconjunto de la izquierda.
    busca(p,iNum/2);
    
    // Mirar en el subconjunto de la derecha.
    busca(p+iNum/2,(iNum+1)/2);
    
    // Hallar los lÌmites del conjunto central.
    for(iDesde=iNum/2; iDesde>0 && p[iNum/2].fX-p[iDesde].fX<dDistMin; iDesde--);
    for(iHasta=iNum/2; iHasta<iNum-1 && p[iHasta].fX-p[iNum/2].fX<dDistMin; iHasta++);
    
    
    for(iA=iDesde;iA<=iHasta;iA++)
        for(iB=iA+1;iB<=iHasta;iB++)
            if((dD=dDist(p[iA],p[iB]))<dDistMin)
            {
                dDistMin=dD;
                pC1.fX=p[0].fX;
                pC1.fY=p[0].fY;
                pC2.fX=p[1].fX;
                pC2.fY=p[1].fY;
            }
}

// Funcion auxiliar del qsort.



int main()
{
    int iA,iNum;
    float dX,dY;
    punto p[MAX];
    
    cin>>iNum;
    for(iA=0;iA<iNum;iA++)
    {
        cin>>dX>>dY;
        p[iA].fX=dX;
        p[iA].fY=dY;
    }
    
    busca(p,iNum); // Hacer la primera busqueda.
    
    cout<<"The distance of best friends are: "<<fixed<<setprecision(2)<<dDistMin<<endl;
    
    
}

