#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <cstring>
#include <string>
#include <limits>
#include <unordered_set>
#include "graph.h"

using namespace std;

// Global variables
map<string, int> m;               // For locations
Graph graph;                      // Storing travel data
map<string, float> customValue;   // To store custom values based on the user's criteria
map<string, string> parent;       // To track the travel path (parent nodes)

// Forward declarations
void initLocations();
void loadEdges();
void print_path(const string& dest);
void find_plan_based_on_days(const string& current_location, float total_days);

// Initialize locations
void initLocations() {
    string locations[4] = {
        "Dehradun", "Mussoorie", "Dhanaulti", "Rishikesh"
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
// void loadEdges() {
//     fstream f3("places.txt", ios::in);  // Open in text mode
//     if (!f3) {
//         cout << "Error opening places.txt. Please check the file path.\n";
//         return;
//     }

//     string dest_1, dest_2;
//     float cost, time, rating;
//     int connectivity;

//     // Read the file line by line and extract edge information
//     cout<< "entering the edge loading loop ... "<<"\n";
//     while (f3 >> dest_1 >> dest_2 >> cost >> time >> rating >> connectivity) {
//         graph.addEdge(dest_1, dest_2, cost, time, rating, connectivity);  // Add edges to the graph
//         cout<<"edge added successfully"<<"\n";
//     }

//     f3.close();
//     cout << "Loaded edges into the graph successfully.\n";
// }

void loadEdges() {
    fstream f3("places.txt", ios::in);

    

    string dest_1, dest_2;
    float cost, time, rating;
    int connectivity;

    while (f3 >> dest_1 >> dest_2 >> cost >> time >> rating >> connectivity) {
        cout << "Read: " << dest_1 << " " << dest_2 << " " << cost << " " << time << " " << rating << " " << connectivity << endl;
        graph.addEdge(dest_1, dest_2, cost, time, rating, connectivity);
        cout << "Edge added successfully: " << dest_1 << " -> " << dest_2 << endl;
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

// Function to find a travel plan based on current location and trip duration
void find_plan_based_on_days(const string& current_location, float total_days) {
    cout << "\nPlanning itinerary for " << current_location << " with total days: " << total_days << " days.\n";

    // Check if the current location exists in the map
    if (m.count(current_location) == 0) {
        cout << "\nLocation '" << current_location << "' not found!\n";
        return;
    }

    unordered_set<string> visited; // Keep track of visited locations
    visited.insert(current_location);
    
    float remaining_days = total_days; // Track remaining days
    string current_node = current_location;
    parent[current_node] = current_node; // Initialize parent of starting location to itself

    // Loop until remaining days are exhausted or no next location is available
    while (remaining_days > 0) {
        cout << "\nCurrent location: " << current_node << ", Remaining days: " << remaining_days << "\n";
        
        float max_value = -1.0;
        string next_location;
        float travel_time = 0.0;

        // Iterate over adjacent nodes
        for (auto& neighbor : graph.m[current_node]) {
            string neighbor_node = neighbor.first;
            auto& [distance, duration, rating, connectivity] = neighbor.second;

            cout << "current_node distance-> " << distance
                << "current_node duration-> " << duration
                << "current_node rating-> " << rating
                << "current_node connectivity-> " << connectivity << "\n";

            // Skip visited nodes 
            if (visited.count(neighbor_node) > 0) continue;

            // Calculate value based on distance, duration, rating, and connectivity
            float node_value = distance * 1.0 + duration * 1.0 + rating * 1.0 + connectivity;
            cout << "current Node value -> " << node_value<<"\n";

            // Debugging output
            cout << "Considering neighbor: " << neighbor_node 
                 << " with travel duration: " << duration 
                 << " and node value: " << node_value << "\n";

            // Find the highest-value unvisited node within remaining days
            if (node_value > max_value && duration <= remaining_days) {
                max_value = node_value;
                next_location = neighbor_node;
                travel_time = duration;
            }
        }

        // Check if a valid next location was found
        // if (next_location.empty()) {
        //     cout << "No further destinations within the remaining days.\n";
        //     break;
        // }

        // Visit the next location
        cout << "Travelling to: " << next_location << " (Value: " << max_value << ", Duration: " << travel_time << " days)\n";
        visited.insert(next_location);
        remaining_days -= travel_time;
        parent[next_location] = current_node; // Set parent of next location to current node
        current_node = next_location;
    }

    cout << "\nItinerary planning completed. Travel path:\n";
    for (const auto& location : visited) {
        cout << "Path to " << location << ": ";
        print_path(location);
        cout << endl;
    }
}

int main() {
    // Initialize the available locations
    initLocations();
    loadEdges(); // Load edges from the file into the graph

    // Input current location and total days for the trip
    string current_location;
    float total_days;

    cout << "\nEnter your current location: ";
    getline(cin, current_location);
    cout << "You entered location: " << current_location << endl;

    cout << "Enter the number of days for your trip: ";
    while (!(cin >> total_days) || total_days <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a positive number for the days: ";
    }
    cout << "You entered total days: " << total_days << endl;

    // Call function to find a plan based on current location and days
    //find_plan_based_on_days(current_location, total_days);

    return 0;
}
