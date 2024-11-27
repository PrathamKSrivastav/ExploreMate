#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

class Question {
    string text;
    double bias;

public:
    Question(const string& text, double bias) : text(text), bias(bias) {}

    string getText() const {
        return text;
    }

    double getBias() const {
        return bias;
    }
};

class Edge {
    string destination;
    float distance;
    int duration;
    float rating;
    int connectivity;

public:
    Edge(const string& destination, float distance, int duration, float rating, int connectivity)
        : destination(destination), distance(distance), duration(duration), rating(rating), connectivity(connectivity) {}

    void updateRating(int feedback, float questionBias) {
        if (feedback == 1) {
            rating -= questionBias * 2.0f;
        } else if (feedback == 2) {
            rating -= questionBias * 1.0f;
        } else if (feedback == 3) {
            rating += questionBias * 1.0f;
        } else if (feedback == 4) {
            rating += questionBias * 1.5f;
        } else if (feedback == 5) {
            rating += questionBias * 2.0f;
        }

        if (rating > 5) {
            rating = 5 - (rating - 5) * 0.5f;
            if (rating > 5) {
                rating = 5;
            }
        } else if (rating < 1) {
            rating = 1 + (1 - rating) * 0.5f;
            if (rating < 1) {
                rating = 1;
            }
        }
    }

    string toString() const {
        return "Edge{destination='" + destination + "', rating=" + to_string(rating) + "}";
    }

    const string& getDestination() const {
        return destination;
    }

    float getRating() const {
        return rating;
    }
};

class FeedbackSystem {
    map<string, vector<Edge>> graphEdges;
    map<string, vector<Question>> edgeQuestions;

public:
    FeedbackSystem(const map<string, vector<Edge>>& graphEdges) : graphEdges(graphEdges) {}

    void addQuestions(const string& edgeKey, const vector<Question>& questions) {
        edgeQuestions[edgeKey] = questions;
    }

   void collectFeedbackForEdge(const string& startNode, const string& endNode) {
    string edgeKey = startNode + "-" + endNode;

    auto it = graphEdges.find(startNode);
    if (it == graphEdges.end()) {
        cout << "No edges connected to " << startNode << endl;
        return;
    }

    Edge* edgeToUpdate = nullptr;
    for (auto& edge : it->second) {
        if (edge.getDestination() == endNode) {
            edgeToUpdate = &edge;
            break;
        }
    }

    if (!edgeToUpdate) {
        cout << "No edge found between " << startNode << " and " << endNode << endl;
        return;
    }

    auto questionsIt = edgeQuestions.find(edgeKey);
    if (questionsIt == edgeQuestions.end() || questionsIt->second.empty()) {
        cout << "No feedback questions configured for the edge: " << edgeKey << endl;
        return;
    }

    cout << "You are now providing feedback for the edge from " << startNode << " to " << endNode << endl;

    for (const auto& question : questionsIt->second) {
        cout << question.getText() << endl;
        cout << "Rate your response (1 to 5): ";

        int feedback;
        cin >> feedback;

        while (feedback < 1 || feedback > 5) {
            cout << "Invalid response. Please rate between 1 and 5: ";
            cin >> feedback;
        }

        edgeToUpdate->updateRating(feedback, static_cast<float>(question.getBias()));
    }

    cout << "Feedback for edge from " << startNode << " to " << endNode << " has been recorded." << endl;
    cout << "Updated rating for this edge: " << fixed << setprecision(2) << edgeToUpdate->getRating() << endl;
}

    void displayResults() const {
        cout << "Updated Edge Ratings:" << endl;
        for (const auto& entry : graphEdges) {
            for (const auto& edge : entry.second) {
                cout << edge.toString() << endl;
            }
        }
    }
};

int feedback() {
    map<string, vector<Edge>> graphEdges = {
        {"Dehradun", {
            Edge("Mussoorie", 50, 1, 4.7f, 1),
            Edge("Rishikesh", 70, 2, 4.5f, 1)
        }},
        {"Mussoorie", {
            Edge("Dehradun", 50, 1, 4.7f, 1),
            Edge("Dhanaulti", 40, 1, 4.9f, 1)
        }}
    };

    FeedbackSystem feedbackSystem(graphEdges);

    feedbackSystem.addQuestions("Dehradun-Mussoorie", {
        Question("How would you rate your overall experience at our suggested location?", 0.4),
        Question("How would you rate the availability of facilities (e.g., restrooms, seating areas)?", 0.6),
        Question("How easy was it to navigate and access the location?", 0.7),
        Question("How engaging did you find the attractions or activities offered?", 0.8)
    });

    feedbackSystem.addQuestions("Dehradun-Rishikesh", {
        Question("How would you rate your overall experience at our suggested location?", 0.4),
        Question("How would you rate the availability of facilities (e.g., restrooms, seating areas)?", 0.6),
        Question("How easy was it to navigate and access the location?", 0.7),
        Question("How engaging did you find the attractions or activities offered?", 0.8)
    });

    string startNode, endNode;
    do {
        cout << "Enter the start location (or type 'exit' to finish): ";
        cin >> startNode;
        if (startNode == "exit") break;

        cout << "Enter the end destination: ";
        cin >> endNode;

        feedbackSystem.collectFeedbackForEdge(startNode, endNode);

    } while (true);

    feedbackSystem.displayResults();

    return 0;
}
