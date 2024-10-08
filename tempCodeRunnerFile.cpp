#include <fstream>
#include <iostream>
#include <map>
#include <cstring>
#include "graph.h"
#include <cstdlib>
#include <stdlib.h>
#include <ctime>

using namespace std;

// Global variables
map<string, int> m;
GraphInt cost_graph;
GraphFloat time_graph;
map<string, string> parent;
map<string, int> dist;

// Forward declaration
void enter();

void initLocations() {
    string locations[5] = {
        "Dehradun", "Mussoorie", "Dhanaulti", "Rishikesh", "Haridwar"
    };
    for (int i = 0; i < 5; i++) {
        m[locations[i]] = 1;  // Initialize map with locations
    }
    cout << "Initiated locations map with custom locations\n";
}

void print_path(string dest) {
    if (parent[dest] == dest) {
        cout << dest << " -->";
        return;
    }
    print_path(parent[dest]);
    cout << dest << " -->";
}

void find_plan_based_on_duration(string current_location, int travel_duration) {
    cout << "\nPlanning an itinerary for " << current_location << " with a travel duration of " << travel_duration << " days.\n";
    
    // Check if the current location exists in the map
    if (m.count(current_location) == 0) {
        cout << "\nLocation not found!\n";
        return;
    }

    // Simulate the logic to provide a travel plan
    cout << "\nEstimated travel cost: " << dist[current_location] * travel_duration << " INR\n";
    cout << "Minimum cost plan: " << (2 * dist[current_location]) + 20000 << " INR\n\n";
    print_path(current_location);
    cout << endl;
}

int main() {
    // Initialize the available locations
    initLocations();

    // Input current location and travel duration
    string current_location;
    int travel_duration;

    cout << "Enter your current location: ";
    cin.ignore();
    getline(cin, current_location);

    cout << "Enter your travel duration (in days): ";
    cin >> travel_duration;

    // Call function to find a plan based on current location and duration
    find_plan_based_on_duration(current_location, travel_duration);

    return 0;
}
