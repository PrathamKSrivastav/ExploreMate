#include <iostream>
#include <fstream>
#include "graph.h" // Include the modified graph.h that uses the Edge class
using namespace std;

int main() {
    // Create 100 Edge objects to represent connections between cities
    Edge E[100];

    // Initialize the edges with data for Dehradun, Mussoorie, Dhanaulti, Rishikesh, and Haridwar
    E[0].init("Dehradun", "Rishikesh", 44, 2.0, 4.5, 1);
    E[1].init("Dehradun", "Mussoorie", 28, 2.0, 4.1, 2);
    E[2].init("Dehradun", "Dhanaulti", 60, 1.0, 4.2, 2);

    E[3].init("Mussoorie", "Dehradun", 28, 2.0, 4.4, 3); // dehradun rate-> 4.4 and duration 2
    E[4].init("Mussoorie", "Dhanaulti", 33, 1.0, 4.2, 2);

    E[5].init("Dhanaulti", "Dehradun", 60, 2.0, 4.4, 3);
    E[6].init("Dhanaulti", "Mussoorie", 33, 2.0, 4.1, 2);

    E[7].init("Rishikesh", "Dehradun", 44, 2.0, 4.4, 3);

    // Open file in binary mode for writing
    fstream f3("places.txt", ios::out | ios::binary);
    if (!f3) {
        cerr << "Error: Unable to create or open places.txt for writing in binary mode.\n";
        return 1; // Exit with an error code
    }

    // Write initialized edges to the file
    for (int i = 0; i < 8; i++) { // Adjust the number of edges based on the number of initializations
        f3.write(reinterpret_cast<const char*>(&E[i]), sizeof(E[i])); // Write as binary
        if (f3.fail()) {
            cerr << "Error: Failed to write edge " << i << " to places.txt\n";
            return 1; // Exit with an error code
        }
        cout << "Edge " << i << " written successfully.\n";
    }

    f3.close();
    cout << "All edges written to places.txt successfully as a binary file.\n";

    return 0;
}
