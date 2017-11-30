#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <omp.h>

using namespace std;

int main(){

    int ins,buscar,i,j;
    //const int base = stoi(argv[1]);
    int l=1000,base=1000;
    int size = base+20;
    double tstart,tend,timeIns=0,timeSearch=0,timeElim=0;
    vector<int>myvector;


    while(l<=1000000){

        srand(l);
        for(i = 1; i<=base; i++){
            ins=rand()%1000;
            myvector.push_back(ins);
        }   
        //insertar
        tstart = omp_get_wtime();
        for(i=0; i<20; i++){
            ins=rand()%1000;
            myvector.push_back(ins);
        }
        tend = omp_get_wtime();
        timeIns += (tend-tstart); 
        //buscar
        tstart = omp_get_wtime();
        for(i=0; i<20; i++){
            j=0;
            ins=rand()%1000;
            //vector <int>::iterator it;
            auto it = myvector.begin();
            while(it!=myvector.end() && j==0){
                if(*it == ins) j=1;
                it++;
            }
        }
        tend = omp_get_wtime();
        timeSearch += (tend-tstart);
        //eliminar
        tstart = omp_get_wtime();
        for(i=0;i<20;i++){
            myvector.pop_back();
        }
        tend = omp_get_wtime();
        timeElim += (tend-tstart);
        l+=1000;
    }
    cout<<"time ins: "<<timeIns/1000000<<endl;
    cout<<"time search: "<<timeSearch/1000000<<endl;
    cout<<"time Elim: "<<timeElim/1000000<<endl;
    return 0;
}
