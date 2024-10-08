#include <fstream>
#include <iostream>
#include <map>
#include <cstring>
#include <limits>
#include "graph.h"  // Ensure this header file contains necessary definitions

using namespace std;

// Global variables
map<string, int> m; // For locations
Graph graph;        // Using the Graph class for storing travel data
map<string, string> parent; // To track paths
map<string, float> customValue; // To store custom values based on the user's criteria

// Forward declarations
void initLocations();
void loadEdges();
void print_path(const string& dest);
void find_plan_based_on_duration(const string& current_location, float travel_duration);

// Initialize locations
void initLocations() {
    string locations[5] = {
        "Dehradun", "Mussoorie", "Dhanaulti", "Rishikesh", "Haridwar"
    };
    for (const auto& location : locations) {
        m[location] = 1;  // Initialize map with locations
    }
    cout << "Initiated locations map with custom locations:\n";
    for (const auto& loc : locations) {
        cout << "- " << loc << endl;  // Display initialized locations
    }
}

// Load edges from the file into the graph
void loadEdges() {
    fstream f3("places.txt", ios::in | ios::binary);
    if (!f3) {
        cout << "Error opening places.txt. Please check the file path.\n";
        return;
    }

    Edge tempEdge;
    while (f3.read((char*)&tempEdge, sizeof(tempEdge))) {
        graph.addEdge(tempEdge.dest_1, tempEdge.dest_2, tempEdge.cost, tempEdge.time, tempEdge.rating, tempEdge.connectivity);
    }
    f3.close();
    cout << "Loaded edges into the graph successfully.\n";
}

// Print the path from the source to destination
void print_path(const string& dest) {
    if (parent[dest] == dest) {
        cout << dest;
        return;
    }
    print_path(parent[dest]);
    cout << " --> " << dest;
}

// Function to find a travel plan based on current location and travel duration
void find_plan_based_on_duration(const string& current_location, float travel_duration) {
    cout << "\nPlanning an itinerary for " << current_location << " with a travel duration of " << travel_duration << " hours.\n";
    
    // Check if the current location exists in the map
    if (m.count(current_location) == 0) {
        cout << "\nLocation '" << current_location << "' not found in the available locations!\n";
        return;
    }

    // Set initial custom values
    for (const auto& loc : m) {
        customValue[loc.first] = numeric_limits<float>::max(); // Use max for float
    }

    customValue[current_location] = 0.0; // Set the custom value for the source to 0
    parent[current_location] = current_location;

    // Call the custom Dijkstra function to find the best routes
    // Ensure you pass all required parameters, replacing the following placeholders with actual values
    float param1 = 1.0; // Replace with actual values relevant to your logic
    float param2 = 1.0; // Replace with actual values
    float param3 = 1.0; // Replace with actual values
    float param4 = 1.0; // Replace with actual values
    dijk_custom_value(current_location, parent, customValue, graph.m, param1, param2, param3, param4); // Ensure this function is defined properly

    // Display the itinerary based on the maximum duration
    cout << "\nPossible routes from '" << current_location << "' within " << travel_duration << " hours:\n";
    bool route_found = false; // Flag to check if any routes were found
    for (const auto& it : customValue) {
        if (it.second <= travel_duration) {
            cout << " - " << current_location << " -> " << it.first << " (Estimated Custom Value: " << it.second << " hours)\n";
            route_found = true; // Set flag to true if at least one route is found
        }
    }

    // If no routes were found within the duration
    if (!route_found) {
        cout << "No routes available within " << travel_duration << " hours.\n";
        return;
    }

    // Optionally, print detailed paths
    cout << "\nDetailed paths:\n";
    for (const auto& it : customValue) {
        if (it.second <= travel_duration) {
            cout << "Path to " << it.first << ": ";
            print_path(it.first);
            cout << endl;
        }
    }
}

int main() {
    // Initialize the available locations
    initLocations();
    loadEdges(); // Load edges from the file into the graph

    // Input current location and travel duration
    string current_location;
    float travel_duration;

    cout << "\nEnter your current location: ";
    cin.ignore();
    getline(cin, current_location);

    cout << "Enter your travel duration (in hours): ";
    cin >> travel_duration;

    // Call function to find a plan based on current location and duration
    find_plan_based_on_duration(current_location, travel_duration);

    return 0;
}
