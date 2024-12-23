#include <iostream>
#include <map>
#include <list>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <set>
#include <tuple> // Include tuple for multiple attributes
#include <limits> // For numeric limits
using namespace std;

class Graph {
public:
    float dist_bias = 0.3, dur_bias = 0.3, rat_bias = 0.3, con_bias = 0.1;

    unordered_map<string, list<pair<string, tuple<int, float, float, int>>>> m; // Using tuple for multiple attributes

    void addEdge(const char src[], const char dest[], float distance, int duration, float rating, int connectivity) {
        string source(src);
        string destination(dest);
        m[source].push_back({destination, {distance, duration, rating, connectivity}});
        m[destination].push_back({source, {distance, duration, rating, connectivity}});
    }

    void updateEdge(const char src[], const char dest[], float newDistance, int newDuration, float newRating, int newConnectivity) {
        string source(src);
        string destination(dest);

        // Update the edge in the adjacency list
        bool edgeUpdated = false;

        for (auto& neighbor : m[source]) {
            if (neighbor.first == destination) {
                neighbor.second = {newDistance, newDuration, newRating, newConnectivity};
                edgeUpdated = true;
                break;
            }
        }

        for (auto& neighbor : m[destination]) {
            if (neighbor.first == source) {
                neighbor.second = {newDistance, newDuration, newRating, newConnectivity};
                break;
            }
        }

        if (edgeUpdated) {
            cout << "Edge from " << source << " to " << destination << " updated successfully.\n";
        } else {
            cout << "Edge from " << source << " to " << destination << " not found.\n";
        }
    }

    float calculateValue(int dist, int duration, float rating, int connectivity) {
        float value = (dist * dist_bias + duration * dur_bias + rating * rat_bias + connectivity * con_bias);
        float max_possible_value = (100 * dist_bias + 10 * dur_bias + 5 * rat_bias + 10 * con_bias);
        return value / max_possible_value;
    }

    void calculateEdgeValuesFromNode(const char src[]) {
        string source(src);
        if (m.find(source) == m.end()) {
            cout << "No edges connected to " << source << ".\n";
            return;
        }

        cout << "Calculating overall values for edges from " << source << ":\n";
        for (auto& neighbor : m[source]) {
            string neighborNode = neighbor.first;
            int distance = get<0>(neighbor.second);
            int duration = get<1>(neighbor.second);
            float rating = get<2>(neighbor.second);
            int connectivity = get<3>(neighbor.second);

            float overallValue = calculateValue(distance, duration, rating, connectivity);
            cout << "Edge to " << neighborNode << ": Overall Value = " << overallValue << endl;
        }
    }

    void initializeEdges(){
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
    }
};
