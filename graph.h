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
    float connectivity; // connectivity

    Edge(const char a[] = "Delhi", const char b[] = "China", int c = 0, float t = 0.00, float r = 0.0, float con = 0.0) {
        dest_1 = a; // Store const char* directly
        dest_2 = b;
        cost = c;
        time = t;
        rating = r;
        connectivity = con;
    }

    void init(const char a[], const char b[], int c, float t, float r, float con) {
        dest_1 = a; // Store const char* directly
        dest_2 = b;
        cost = c;
        time = t;
        rating = r;
        connectivity = con;
    }
};

class GraphInt{
    public:
    int v;
    map<string, list< pair <string, int> > > m;
    void addEdge(string x, string y, int wt){
        m[x].push_back(make_pair(y, wt));
        m[y].push_back(make_pair(x, wt));
    }
};
class GraphFloat{
    public:
    int v;
    map<string, list< pair <string, float> > > m;
    void addEdge(string x, string y, float wt){
        m[x].push_back(make_pair(y, wt));
        m[y].push_back(make_pair(x, wt));
    }
};
class Graph {
public:
    int v;
    map<string, list<pair<string, tuple<int, float, float, float>>>> m; // Using tuple for multiple attributes

    void addEdge(string x, string y, int dist, float dura, float rate, float con) {
        m[x].push_back(make_pair(y, make_tuple(dist, dura, rate, con)));
        m[y].push_back(make_pair(x, make_tuple(dist, dura, rate, con)));
    }
};

// ---------- NEW FUNCTION FOR CUSTOM VALUE CALCULATION ----------
void dijk_custom_value(string src, 
                        map<string, string> &parent, 
                        map<string, float> &customValue, 
                        map<string, list<pair<string, tuple<int, float, float, float>>>> &m,  // Correct map declaration
                        float dist_weight, 
                        float dura_weight, 
                        float rating_weight, 
                        float connectivity_weight) {

    // Initialize custom values to a large number initially
    for (auto p : m) {
        customValue[p.first] = numeric_limits<float>::max(); // Use max for float
    }

    customValue[src] = 0.0; // Set the custom value for the source to 0
    set<pair<float, string>> s; // To maintain and find the next vertex at min custom value
    s.insert(make_pair(0.0, src));
    parent[src] = src;

    while (!s.empty()) {
        auto p = *(s.begin());
        string place = p.second;
        float node_value = p.first;

        // Finalize this node
        s.erase(s.begin());

        // Iterate through the children of the current node
        for (auto child_pair : m[place]) {
            string vertex = child_pair.first;
            auto child_data = child_pair.second;
            int distance = get<0>(child_data);
            float duration = get<1>(child_data);
            float rating = get<2>(child_data);
            float connectivity = get<3>(child_data);

            // Calculate the new custom value using the formula
            float new_value = (distance * dist_weight) + 
                              (duration * dura_weight) + 
                              (rating * rating_weight) + 
                              (connectivity * connectivity_weight);

            // Check if the new custom value is lower than the current value
            if (node_value + new_value < customValue[vertex]) {
                auto f = s.find(make_pair(customValue[vertex], vertex));
                if (f != s.end()) {
                    s.erase(f);
                }
                parent[vertex] = place;
                customValue[vertex] = node_value + new_value;
                s.insert(make_pair(customValue[vertex], vertex));
            }
        }
    }
}
