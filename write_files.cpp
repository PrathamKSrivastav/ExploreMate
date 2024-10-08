#include <iostream>
#include <fstream>
#include "graph.h" // Include the modified graph.h that uses the Edge class
using namespace std;

int main()
{
    // Create 100 Edge objects to represent connections between cities
    Edge E[100];

    // Initialize the edges with data for Dehradun, Mussoorie, Dhanaulti, Rishikesh, and Haridwar
    E[0].init("Dehradun", "Rishikesh", 44, 2.0, 4.5, 1.0);
    E[1].init("Dehradun", "Mussoorie", 28, 2.0, 4.1, 2.0);
    E[2].init("Dehradun", "Dhanulti", 60, 1.0, 4.2, 2.0);

    E[3].init("Mussoorie", "Dehradun", 28, 2.0, 4.4, 3.0); // dehradun rate-> 4.4 and duration 2
    E[4].init("Mussoorie", "Dhanulti", 33, 1.0, 4.2, 2.0);

    E[5].init("Dhanulti", "Dehradun", 60, 2.0, 4.4, 3.0);
    E[6].init("Dhanulti", "Mussoorie", 33, 2.0, 4.1, 2.0);

    E[7].init("Rishikesh", "Dehradun", 44,2.0,4.4,3.0);

    // Write the edges to a file
    fstream f3;
    f3.open("places.txt", ios::out);
    for (int i = 0; i < 10; i++) 
    { // Adjust the number of edges based on the number of initializations
        f3.write((char *)&E[i], sizeof(E[i]));
    }
    f3.close();

    return 0;
}
