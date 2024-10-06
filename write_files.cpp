#include<iostream>
#include<fstream>
#include "graph.h"

int main(){
    Edge E[10];

    

    fstream f3;
    f3.open("places.txt", ios::out);
    
    for(int i=0; i<=85; i++){
        f3.write( (char*)&E[i], sizeof(E[i]) );
    }
    f3.close();

    return 0;
}