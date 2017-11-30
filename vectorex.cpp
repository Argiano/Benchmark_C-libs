#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(){

    int ins,buscar,i,j;
    //const int base = stoi(argv[1]);
    int l=1000,base=1000;
    int size = base+20;
    vector<int>myvector;


    while(l<=1000000){

        srand(l);
        for(i = 1; i<=base; i++){
            ins=rand()%1000;
            myvector.push_back(ins);
        }   
        //insertar
        for(i=0; i<20; i++){
            ins=rand()%1000;
            myvector.push_back(ins);
        }
        //buscar
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
        //eliminar
        for(i=0;i<20;i++){
            myvector.pop_back();
        }
        l+=1000;
    }
    return 0;
}