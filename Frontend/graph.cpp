#include "graph.h"
#include <iostream>

// Constructor
Graph::Graph()
    : dist_bias(0.3), dur_bias(0.3), rat_bias(0.3), con_bias(0.1) {}

// Method to add an edge
void Graph::addEdge(const std::string &src, const std::string &dest, float distance, int duration, float rating, int connectivity) {
    // Add bidirectional edge between src and dest
    m[src].push_back({dest, {distance, duration, rating, connectivity}});
    m[dest].push_back({src, {distance, duration, rating, connectivity}});
}

// Method to update an edge
void Graph::updateEdge(const std::string &src, const std::string &dest, float newDistance, int newDuration, float newRating, int newConnectivity) {
    bool edgeUpdated = false;

    // Update edge in src's adjacency list
    for (auto &neighbor : m[src]) {
        if (neighbor.first == dest) {
            neighbor.second = {newDistance, newDuration, newRating, newConnectivity};
            edgeUpdated = true;
            break;
        }
    }

    // Update edge in dest's adjacency list
    for (auto &neighbor : m[dest]) {
        if (neighbor.first == src) {
            neighbor.second = {newDistance, newDuration, newRating, newConnectivity};
            break;
        }
    }

    // Notify the result of the update
    if (edgeUpdated) {
        std::cout << "Edge from " << src << " to " << dest << " updated successfully.\n";
    } else {
        std::cout << "Edge from " << src << " to " << dest << " not found.\n";
    }
}

// Method to calculate the value of an edge
float Graph::calculateValue(int dist, int duration, float rating, int connectivity) {
    // Calculate weighted value of an edge
    float value = (dist * dist_bias + duration * dur_bias + rating * rat_bias + connectivity * con_bias);
    float max_possible_value = (100 * dist_bias + 10 * dur_bias + 5 * rat_bias + 10 * con_bias);
    return value / max_possible_value; // Normalize the value
}

// Method to calculate edge values from a given node
void Graph::calculateEdgeValuesFromNode(const std::string &src) {
    // Check if the node exists in the graph
    if (m.find(src) == m.end()) {
        std::cout << "No edges connected to " << src << ".\n";
        return;
    }

    std::cout << "Calculating overall values for edges from " << src << ":\n";
    // Iterate through all neighbors of src
    for (const auto &neighbor : m[src]) {
        const std::string &neighborNode = neighbor.first;
        int distance = std::get<0>(neighbor.second);
        int duration = std::get<1>(neighbor.second);
        float rating = std::get<2>(neighbor.second);
        int connectivity = std::get<3>(neighbor.second);

        // Compute overall value for the edge
        float overallValue = calculateValue(distance, duration, rating, connectivity);
        std::cout << "Edge to " << neighborNode << ": Overall Value = " << overallValue << std::endl;
    }
}

// Method to initialize edges in the graph
void Graph::initializeEdges() {
    // Adding edges with predefined weights and biases
    addEdge("Dehradun", "Mussoorie", 50, 1.5, 4.7, 1);
    addEdge("Dehradun", "Rishikesh", 70, 2.0, 4.5, 1);
    addEdge("Mussoorie", "Dhanaulti", 40, 1.0, 4.9, 1);
    addEdge("Mussoorie", "Rishikesh", 80, 2.5, 4.3, 1);
    addEdge("Dhanaulti", "Dehradun", 60, 2.0, 4.4, 3);

    addEdge("Mussoorie", "Landour", 10, 0.5, 4.8, 1);
    addEdge("Mussoorie", "Sahastradhara", 35, 1.2, 4.6, 1);
    addEdge("Sahastradhara", "Dhanaulti", 50, 1.8, 4.7, 1);
    addEdge("Dhanaulti", "Kantal", 30, 1.0, 4.5, 2);
    addEdge("Kantal", "Chamba", 40, 1.5, 4.6, 2);

    addEdge("Mussoorie", "Nag Tibba", 55, 2.0, 4.8, 1);
    addEdge("Nag Tibba", "Chakrata", 60, 2.5, 4.7, 2);

    addEdge("Dehradun", "Sahastradhara", 40, 1.5, 4.6, 1);
    addEdge("Sahastradhara", "Mussoorie", 35, 1.2, 4.6, 1);

    addEdge("Rishikesh", "Shivpuri", 25, 1.0, 4.4, 1);
    addEdge("Rishikesh", "Haridwar", 25, 1.0, 4.5, 1);
    addEdge("Haridwar", "Roorkee", 30, 1.2, 4.3, 2);

    addEdge("Dehradun", "Haridwar", 45, 1.6, 4.5, 1);
    addEdge("Haridwar", "Shivpuri", 30, 1.0, 4.2, 2);
    addEdge("Haridwar", "Sahastradhara", 60, 2.0, 4.4, 2);
    addEdge("Rishikesh", "Dhanaulti", 75, 3.0, 4.6, 1);
    addEdge("Rishikesh", "Chakrata", 90, 3.5, 4.5, 2);
    addEdge("Dhanaulti", "Sahastradhara", 70, 2.5, 4.5, 1);
    addEdge("Sahastradhara", "Kantal", 50, 1.8, 4.7, 2);
    addEdge("Sahastradhara", "Landour", 80, 2.8, 4.6, 2);
    addEdge("Mussoorie", "Chakrata", 65, 2.4, 4.8, 1);
    addEdge("Chakrata", "Nag Tibba", 70, 3.0, 4.9, 2);
    addEdge("Nag Tibba", "Kantal", 45, 1.8, 4.7, 3);
    addEdge("Landour", "Chamba", 75, 2.5, 4.6, 2);
    addEdge("Landour", "Dehradun", 35, 1.3, 4.7, 1);
    addEdge("Chamba", "Roorkee", 90, 3.5, 4.4, 2);
    addEdge("Chamba", "Haridwar", 100, 4.0, 4.3, 3);
    addEdge("Rishikesh", "Roorkee", 60, 2.0, 4.4, 1);

    // Additional edges can be added here as needed
}

// Function to suggest a path based on available days
vector<string> Graph::suggestPath(const string &currentLocation, float totalDays) {
    cout << "\nPlanning itinerary for " << currentLocation << " with total days: " << totalDays << " days.\n";

    unordered_set<string> visited;
    visited.insert(currentLocation);

    vector<string> path;
    path.push_back(currentLocation);

    float remainingDays = totalDays;

    string currentNode = currentLocation;

    while (remainingDays > 0) {
        cout << "\nCurrent location: " << currentNode << ", Remaining days: " << remainingDays << "\n";

        float maxValue = -1.0;
        string nextLocation;
        float travelDuration = 0.0;

        for (const auto &neighbor : m[currentNode]) {
            string neighborNode = neighbor.first;
            auto [distance, duration, rating, connectivity] = neighbor.second;

            if (visited.count(neighborNode) > 0) continue;

            float nodeValue = calculateValue(distance, duration, rating, connectivity);
            cout << "Considering neighbor: " << neighborNode << " with travel duration: " << duration
                 << " and calculated value: " << nodeValue << "\n";

            if (nodeValue > maxValue && duration <= remainingDays) {
                maxValue = nodeValue;
                nextLocation = neighborNode;
                travelDuration = duration;
            }
        }

        if (nextLocation.empty()) {
            cout << "No further destinations within the remaining days.\n";
            break;
        }

        cout << "Traveling to: " << nextLocation << " (Value: " << maxValue << ", Duration: " << travelDuration << " days)\n";
        visited.insert(nextLocation);
        path.push_back(nextLocation);

        remainingDays -= travelDuration;
        currentNode = nextLocation;
    }

    // cout << "\nItinerary planning completed. Travel path to take:\n";
    // for (size_t i = 0; i < path.size(); ++i) {
    //     cout << path[i];
    //     if (i < path.size() - 1) cout << " --> ";
    // }
    // cout << "\n";
    return path;
}

// Function to suggest a circular path
void Graph::suggestCircuitPath(const string &startLocation, float totalDays) {
    cout << "\nPlanning circular itinerary for " << startLocation << " with total days: " << totalDays << " days.\n";

    unordered_set<string> visited;
    visited.insert(startLocation);

    vector<string> path;
    path.push_back(startLocation);

    float remainingDays = totalDays;
    float totalDistance = 0.0;
    string currentNode = startLocation;

    while (remainingDays > 0) {
        cout << "\nCurrent location: " << currentNode << ", Remaining days: " << remainingDays << "\n";

        float maxValue = -1.0;
        string nextLocation;
        float travelDuration = 0.0;
        float travelDistance = 0.0;

        for (const auto &neighbor : m[currentNode]) {
            string neighborNode = neighbor.first;
            auto [distance, duration, rating, connectivity] = neighbor.second;

            if (visited.count(neighborNode) > 0) continue;

            float nodeValue = calculateValue(distance, duration, rating, connectivity);
            cout << "Considering neighbor: " << neighborNode << " with travel duration: " << duration
                 << " and calculated value: " << nodeValue << "\n";

            if (nodeValue > maxValue && duration <= remainingDays) {
                maxValue = nodeValue;
                nextLocation = neighborNode;
                travelDuration = duration;
                travelDistance = distance;
            }
        }

        if (nextLocation.empty()) {
            cout << "No further destinations within the remaining days.\n";
            break;
        }

        cout << "Traveling to: " << nextLocation << " (Value: " << maxValue
             << ", Duration: " << travelDuration << " days, Distance: " << travelDistance << " km)\n";
        visited.insert(nextLocation);
        path.push_back(nextLocation);
        totalDistance += travelDistance;

        remainingDays -= travelDuration;
        currentNode = nextLocation;
    }

    if (m.count(currentNode) > 0) {
        for (const auto &neighbor : m[currentNode]) {
            if (neighbor.first == startLocation) {
                auto [distance, duration, rating, connectivity] = neighbor.second;
                totalDistance += distance;
                cout << "Returning to starting location " << startLocation << " via path distance: " << distance << " km.\n";
                break;
            }
        }
    }

    cout << "\nItinerary planning completed. Travel circuit:\n";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) cout << " --> ";
    }
    cout << " --> " << startLocation << "\n";

    cout << "Total distance traveled: " << totalDistance << " km.\n";
}

