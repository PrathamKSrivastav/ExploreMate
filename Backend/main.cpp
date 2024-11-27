#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <cstring>
#include <string>
#include <limits>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include "graph.h"

using namespace std;

// Global variables
Graph graph;                      // Storing travel data
map<string, string> parent;       // To track the travel path (parent nodes)

// Function to plan the travel path based on total days
void suggestPath(const string& currentLocation, float totalDays) {
    cout << "\nPlanning itinerary for " << currentLocation << " with total days: " << totalDays << " days.\n";

    unordered_set<string> visited; // Track visited locations
    visited.insert(currentLocation);

    vector<string> path; // To store the sequence of travel locations
    path.push_back(currentLocation);

    map<string, float> travelDurations; // Map to store duration for each node
    float remainingDays = totalDays; // Remaining days for the trip

    // Subtract the duration of the starting node if explicitly provided
    float startingNodeDuration = 0.0;
    if (graph.m.count(currentLocation) > 0) {
        for (const auto& neighbor : graph.m[currentLocation]) {
            auto [distance, duration, rating, connectivity] = neighbor.second;
            startingNodeDuration = duration; // Assume the node's own "duration" is found here
            break;
        }
    }

    // Deduct starting node's duration
    remainingDays -= startingNodeDuration;
    cout << "Starting at " << currentLocation 
         << " subtracting its duration: " << startingNodeDuration 
         << " days. Remaining days: " << remainingDays << "\n";

    string currentNode = currentLocation;

    while (remainingDays > 0) {
        cout << "\nCurrent location: " << currentNode << ", Remaining days: " << remainingDays << "\n";

        float maxValue = -1.0;
        string nextLocation;
        float travelDuration = 0.0;

        // Check all neighbors of the current node
        for (const auto& neighbor : graph.m[currentNode]) {
            string neighborNode = neighbor.first;
            auto [distance, duration, rating, connectivity] = neighbor.second;

            // Skip visited nodes
            if (visited.count(neighborNode) > 0) continue;

            // Calculate value for the neighbor
            float nodeValue = graph.calculateValue(distance, duration, rating, connectivity);
            cout << "Considering neighbor: " << neighborNode 
                 << " with travel duration: " << duration 
                 << " and calculated value: " << nodeValue << "\n";

            // Select the highest-value unvisited node within the remaining days
            if (nodeValue > maxValue && duration <= remainingDays) {
                maxValue = nodeValue;
                nextLocation = neighborNode;
                travelDuration = duration;
            }
        }

        // If no valid next location is found, stop
        if (nextLocation.empty()) {
            cout << "No further destinations within the remaining days.\n";
            break;
        }

        // Move to the next location
        cout << "Traveling to: " << nextLocation 
             << " (Value: " << maxValue 
             << ", Duration: " << travelDuration << " days)\n";
        visited.insert(nextLocation);
        path.push_back(nextLocation);

        // Store the travel duration for the current edge
        travelDurations[nextLocation] = travelDuration;

        remainingDays -= travelDuration;
        currentNode = nextLocation;
    }

    // Output the planned path
    cout << "\nItinerary planning completed. Travel path to take:\n";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " --> ";
        }
    }
    cout << "\n";
}

void suggestCircuitPath(const string& startLocation, float totalDays) {
    cout << "\nPlanning itinerary for " << startLocation << " with total days: " << totalDays << " days.\n";

    unordered_set<string> visited; // Track visited locations
    visited.insert(startLocation);

    vector<string> path; // To store the sequence of travel locations
    path.push_back(startLocation);

    float remainingDays = totalDays; // Remaining days for the trip
    float totalDistance = 0.0;       // Total distance traveled
    string currentNode = startLocation;

    // Deduct the starting node's duration
    float startingNodeDuration = 0.0;
    if (graph.m.count(startLocation) > 0) {
        for (const auto& neighbor : graph.m[startLocation]) {
            auto [distance, duration, rating, connectivity] = neighbor.second;
            startingNodeDuration = duration; // Assume the node's "duration" is found here
            break;
        }
    }

    remainingDays -= startingNodeDuration;
    cout << "Starting at " << startLocation 
         << " subtracting its duration: " << startingNodeDuration 
         << " days. Remaining days: " << remainingDays << "\n";

    while (remainingDays > 0) {
        cout << "\nCurrent location: " << currentNode << ", Remaining days: " << remainingDays << "\n";

        float maxValue = -1.0;
        string nextLocation;
        float travelDuration = 0.0;
        float travelDistance = 0.0;

        // Check all neighbors of the current node
        for (const auto& neighbor : graph.m[currentNode]) {
            string neighborNode = neighbor.first;
            auto [distance, duration, rating, connectivity] = neighbor.second;

            // Skip visited nodes
            if (visited.count(neighborNode) > 0) continue;

            // Calculate value for the neighbor
            float nodeValue = graph.calculateValue(distance, duration, rating, connectivity);
            cout << "Considering neighbor: " << neighborNode 
                 << " with travel duration: " << duration 
                 << " and calculated value: " << nodeValue << "\n";

            // Select the highest-value unvisited node within the remaining days
            if (nodeValue > maxValue && duration <= remainingDays) {
                maxValue = nodeValue;
                nextLocation = neighborNode;
                travelDuration = duration;
                travelDistance = distance;
            }
        }

        // If no valid next location is found, stop
        if (nextLocation.empty()) {
            cout << "No further destinations within the remaining days.\n";
            break;
        }

        // Move to the next location
        cout << "Traveling to: " << nextLocation 
             << " (Value: " << maxValue 
             << ", Duration: " << travelDuration 
             << " days, Distance: " << travelDistance << " km)\n";
        visited.insert(nextLocation);
        path.push_back(nextLocation);
        totalDistance += travelDistance;

        remainingDays -= travelDuration;
        currentNode = nextLocation;
    }

    // Add the distance to return to the start location
    if (graph.m.count(currentNode) > 0) {
        bool foundReturnPath = false;
        for (const auto& neighbor : graph.m[currentNode]) {
            if (neighbor.first == startLocation) {
                auto [distance, duration, rating, connectivity] = neighbor.second;
                totalDistance += distance; // Add the return distance to the starting node
                cout << "Returning to starting location " << startLocation 
                     << " via path distance: " << distance << " km.\n";
                foundReturnPath = true;
                break;
            }
        }
        if (!foundReturnPath) {
            cout << "No direct path back to the starting location: " << startLocation << "\n";
        }
    }

    // Output the planned path
    cout << "\nItinerary planning completed. Travel circuit:\n";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " --> ";
        }
    }
    cout << " --> " << startLocation << "\n";

    cout << "Total distance traveled: " << totalDistance << " km.\n";
}

void suggestAlternativeRoutes(const string &currentLocation, float totalDays, vector<string> &alternate1, vector<string> &alternate2, vector<string> &alternate3) {
    vector<vector<string>> alternativeRoutes;

    // Generate exactly 3 alternative routes
    for (int routeIndex = 0; routeIndex < 3; ++routeIndex) { // Always 3 routes
        unordered_set<string> visited;
        visited.insert(currentLocation);

        vector<string> path;
        path.push_back(currentLocation);

        float remainingDays = totalDays;
        string currentNode = currentLocation;

        // Handle starting node duration
        float startingNodeDuration = 0.0;
        if (graph.m.count(currentLocation) > 0) {
            for (const auto &neighbor : graph.m[currentLocation]) {
                auto [distance, duration, rating, connectivity] = neighbor.second;
                startingNodeDuration = duration;
                break;
            }
        }

        remainingDays -= startingNodeDuration;

        // Generate route using randomness
        while (remainingDays > 0) {
            vector<pair<string, float>> candidateLocations;

            // Collect potential next locations
            for (const auto &neighbor : graph.m[currentNode]) {
                string neighborNode = neighbor.first;
                auto [distance, duration, rating, connectivity] = neighbor.second;

                // Skip visited nodes
                if (visited.count(neighborNode) > 0)
                    continue;

                // Check if location can be visited
                if (duration <= remainingDays) {
                    float nodeValue = graph.calculateValue(distance, duration, rating, connectivity);
                    candidateLocations.push_back({neighborNode, nodeValue});
                }
            }

            // If no candidates, break
            if (candidateLocations.empty())
                break;

            // Sort candidates by value
            sort(candidateLocations.begin(), candidateLocations.end(),
                 [](const auto &a, const auto &b) { return a.second > b.second; });

            // Select from top candidates with some randomness
            int selectionIndex = min(
                static_cast<int>(candidateLocations.size() - 1),
                max(0, static_cast<int>(rand() % candidateLocations.size()) - routeIndex)
            );

            string nextLocation = candidateLocations[selectionIndex].first;
            float travelDuration = 0.0;

            // Find the actual duration for the selected location
            for (const auto &neighbor : graph.m[currentNode]) {
                if (neighbor.first == nextLocation) {
                    auto [distance, duration, rating, connectivity] = neighbor.second;
                    travelDuration = duration;
                    break;
                }
            }

            // Update path and tracking variables
            visited.insert(nextLocation);
            path.push_back(nextLocation);
            remainingDays -= travelDuration;
            currentNode = nextLocation;
        }

        // Store the generated route
        alternativeRoutes.push_back(path);
    }

    // Ensure there are always 3 routes, even if some are duplicates
    while (alternativeRoutes.size() < 3) {
        alternativeRoutes.push_back(alternativeRoutes.back());
    }

    // Assign routes to output arrays
    alternate1 = alternativeRoutes[0];
    alternate2 = alternativeRoutes[1];
    alternate3 = alternativeRoutes[2];

    // Output alternative routes (optional)
    cout << "\nGenerated Alternative Routes:\n";
    for (int i = 0; i < 3; ++i) {
        cout << "Route " << (i + 1) << ": ";
        for (size_t j = 0; j < alternativeRoutes[i].size(); ++j) {
            cout << alternativeRoutes[i][j];
            if (j < alternativeRoutes[i].size() - 1)
                cout << " --> ";
        }
        cout << "\n";
    }
}


int main() {
    // Initialize the graph with edges
    graph.initializeEdges();
    // Input current location and trip duration
    string currentLocation;
    float totalDays;

    cout << "\nEnter your current location: ";
    getline(cin, currentLocation);
    cout << "You entered location: " << currentLocation << endl;

    cout << "Enter the number of days for your trip: ";
    while (!(cin >> totalDays) || totalDays <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a positive number for the days: ";
    }
    cout << "You entered total days: " << totalDays << endl;

    // Plan and suggest the path
    suggestPath(currentLocation, totalDays);
    cout << "#######################################################################"<< endl;
    vector<string> route1, route2, route3;
    suggestAlternativeRoutes(currentLocation, totalDays, route1, route2, route3);

    return 0;
}
