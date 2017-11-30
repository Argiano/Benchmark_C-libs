#include <array>
#include <algorithm>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
    int iteracion=1000,j,instancia,buscar;
    array<int,1000020> myarray;
    while(iteracion<=1000000){
        srand(iteracion);
        for(j=iteracion-1000; j<iteracion-20; j++){
            instancia=rand()%100;
            myarray.at(j)=instancia;
        }
        //insertar
        for(j=0;j<20;j++){
            instancia=rand()%100;
            myarray.at(iteracion-20+j)=instancia;
        }
        //buscar
        for(j=0;j<20;j++){
            buscar=rand()%100;
            instancia=0;
            while(myarray.at(instancia)!=buscar) instancia++;
        }
        //eliminar
        srand(1000);
        for(j=0;j<20;j++){
            instancia=rand()%(1000);
            myarray[instancia]=NULL;
        }
        iteracion+=1000;
    }
}