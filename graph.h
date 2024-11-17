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

class Edge {
public:
    const char* dest_1;
    const char* dest_2;
    int cost;          // distance
    float time;       // duration
    float rating;     // rating
    int connectivity; // connectivity

    Edge(const char a[] = "Delhi", const char b[] = "China", int c = 0, float t = 0.00, float r = 0.0, int con = 0){
        dest_1 = a; // Store const char* directly
        dest_2 = b;
        cost = c;
        time = t;
        rating = r;
        connectivity = con;
    }

    void init(const char a[], const char b[], int c, float t, float r, int con) {
        dest_1 = a; // Store const char* directly
        dest_2 = b;
        cost = c;
        time = t;
        rating = r;
        connectivity = con;
    }
};

class Graph {
public:
    float dist_bias = 0.3, dur_bias = 0.3, rat_bias = 0.3, con_bias = 0.1;

    unordered_map<string, list<pair<string, tuple<int, float, float, int>>>> m; // Using tuple for multiple attributes

    // void addEdge(string x, string y, int dist, float dura, float rate, int con) {
    //     m[x].push_back(make_pair(y, make_tuple(dist, dura, rate, con)));
    //     cout << "Edge added: " << x << " -> " << y << endl;
    // }
    void addEdge(const char src[], const char dest[], int distance, int duration, float rating, int connectivity) {
        string source(src);
        string destination(dest);
        m[source].push_back({destination, {distance, duration, rating, connectivity}});
        m[destination].push_back({source, {distance, duration, rating, connectivity}});
    }

    void updateEdge(const char src[], const char dest[], int newDistance, int newDuration, float newRating, int newConnectivity) {
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

    // void suggestPath(const char src[], float totalDays) {
    //     string source(src);

    //     if (m.find(source) == m.end()) {
    //         cout << "Source node " << source << " has no connections.\n";
    //         return;
    //     }

    //     unordered_set<string> visited;
    //     vector<string> path;
    //     path.push_back(source);

    //     while (totalDays > 0) {
    //         visited.insert(source);
    //         float maxValue = -1.0;
    //         string nextNode;
    //         int travelDuration = 0;

    //         for (auto& neighbor : m[source]) {
    //             string neighborNode = neighbor.first;

    //             if (visited.find(neighborNode) != visited.end()) {
    //                 continue; // Skip visited nodes
    //             }

    //             int distance = get<0>(neighbor.second);
    //             int duration = get<1>(neighbor.second);
    //             float rating = get<2>(neighbor.second);
    //             int connectivity = get<3>(neighbor.second);

    //             if (duration > totalDays) {
    //                 continue; // Skip if the neighbor requires more days than available
    //             }

    //             float value = calculateValue(distance, duration, rating, connectivity);
    //             if (value > maxValue) {
    //                 maxValue = value;
    //                 nextNode = neighborNode;
    //                 travelDuration = duration;
    //             }
    //         }

    //         if (maxValue == -1.0) {
    //             break; // No further nodes can be visited
    //         }

    //         totalDays -= travelDuration;
    //         source = nextNode;
    //         path.push_back(source);
    //     }

    //     cout << "Suggested Path:\n";
    //     for (const string& node : path) {
    //         cout << node << " -> ";
    //     }
    //     cout << "End\nRemaining Days: " << totalDays << endl;
    // }
};


// void dijk_custom_value(string src, 
//                         map<string, string> &parent, 
//                         map<string, float> &customValue, 
//                         map<string, list<pair<string, tuple<int, float, float, int>>>> &m, 
//                         float dist_bias, 
//                         float dura_bias, 
//                         float rate_bias,  
//                         float remaining_duration) {

//     for (auto p : m) {
//         customValue[p.first] = numeric_limits<float>::max();
//     }

//     customValue[src] = 0.0;
//     set<pair<float, string>> s;
//     s.insert(make_pair(0.0, src));
//     parent[src] = src;

//     while (!s.empty()) {
//         auto p = *(s.begin());
//         string current_node = p.second;
//         float current_value = p.first;
//         s.erase(s.begin());

//         if (remaining_duration <= 0) {
//             cout << "No more valid nodes within remaining duration." << endl;
//             break;
//         }

//         for (auto child_pair : m[current_node]) {
//             string next_node = child_pair.first;
//             auto child_data = child_pair.second;
//             int distance = get<0>(child_data);
//             float duration = get<1>(child_data);
//             float rating = get<2>(child_data);
//             int connectivity = get<3>(child_data);

//             float value = (distance * dist_bias) + 
//                           (duration * dura_bias) + 
//                           (rating * rate_bias) + 
//                           (connectivity);

//             if (duration <= remaining_duration) {
//                 float new_value = customValue[current_node] + value;

//                 if (new_value < customValue[next_node]) {
//                     auto f = s.find(make_pair(customValue[next_node], next_node));
//                     if (f != s.end()) {
//                         s.erase(f);
//                     }

//                     parent[next_node] = current_node;
//                     customValue[next_node] = new_value;
//                     s.insert(make_pair(customValue[next_node], next_node));

//                     remaining_duration -= duration;
//                 }
//             }
//         }
//     }

//     cout << "Routes from '" << src << "' within duration:\n";
//     for (auto it = customValue.begin(); it != customValue.end(); ++it) {
//         if (it->second < numeric_limits<float>::max()) {
//             cout << " - " << src << " -> " << it->first << " (Value: " << it->second << ")\n";
//         }
//     }
// }

