#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
        char dest_1[20], dest_2[20];
        int dist;
        Edge(char a[] = "Dehradun", char b[] = "Dehradun", int dist=0){ // Constructor
            strcpy(dest_1,a);
            strcpy(dest_2,b);
            dist = dist;
        }
        void init(char a[], char b[], int dist){    // member class to modify the edge after the object is created
            strcpy(dest_1,a);
            strcpy(dest_2,b);
            dist = dist;
        }
};