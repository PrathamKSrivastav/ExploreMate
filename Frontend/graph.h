#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>
#include <unordered_set>
#include <string>
#include <tuple>
#include <QString>

using namespace std;

class Graph {
public:
    Graph();

    void addEdge(const string &src, const string &dest, float distance, int duration, float rating, int connectivity);
    void updateEdge(const string &src, const string &dest, float newDistance, int newDuration, float newRating, int newConnectivity);
    void initializeEdges();
    void calculateEdgeValuesFromNode(const string &src);
    float calculateValue(int dist, int duration, float rating, int connectivity);

    // Add these functions for itinerary planning
    vector<string> suggestPath(const string &currentLocation, float totalDays);
    void suggestCircuitPath(const string &startLocation, float totalDays);
    void suggestAlternativeRoutes(const std::string &currentLocation, float totalDays, int numAlternatives);
    //void suggestAlternativeRoute(const QString &currentLocation, float totalDays, int numAlternatives, QString &alternate1, QString &alternate2, QString &alternate3);
    void suggestAlternativeRoutes(const std::string &currentLocation, float totalDays,
                                  std::vector<std::string> &alternate1,
                                  std::vector<std::string> &alternate2,
                                  std::vector<std::string> &alternate3);

    // Map to store the graph structure
    unordered_map<string, vector<pair<string, tuple<float, int, float, int>>>> m;

private:
    float dist_bias;
    float dur_bias;
    float rat_bias;
    float con_bias;
};

#endif // GRAPH_H
