# ExploreMate

ExploreMate is an intelligent travel itinerary planning software designed to optimize travel plans based on user-defined parameters like **budget**, **time**, and **places to visit**. Built with **C++** and a user-friendly **Qt-based graphical interface**, ExploreMate provides personalized travel suggestions, including alternative routes, to enhance the user's travel experience.

---

## Features

1. **Route Planning**  
   - Dynamically calculates and suggests the best travel routes.
   - Provides **three alternative routes** based on user preferences.

2. **Custom Parameters**  
   - Optimizes itineraries based on **duration**, **ratings**, **distance**, and **connectivity**.

3. **Graph-Based Travel Network**  
   - Uses a graph representation of locations, with each node containing travel-related attributes:
     - Distance
     - Duration
     - Rating
     - Connectivity

4. **Qt Integration**  
   - Interactive dropdowns and input fields for location and travel data.
   - Intuitive **feedback system** for user input on destinations.

5. **Visualization**  
   - Displays suggested routes in a clear, easy-to-understand format using **QString** outputs.

---

## Project Structure

### Main Components

1. **Graph Module**  
   - Handles graph creation and traversal.
   - Implements the `suggestAlternativeRoutes` function to generate alternative paths.

2. **UI (Qt Widgets)**  
   - Dropdown for selecting starting locations.
   - Buttons and forms for feedback and user input.

3. **Algorithm**  
   - Prioritizes travel to neighboring nodes with the highest calculated value (based on custom weightage of parameters).
   - Halts travel if no valid options remain for the given constraints.

---

## Installation and Setup

### Prerequisites
- **Qt Framework**: Install [Qt Creator](https://www.qt.io/product/development-tools) and its necessary components.
- **C++ Compiler**: Ensure you have a working C++ compiler, such as GCC or MSVC.

### Steps
1. Clone the repository:
   ```bash
   git clone https://github.com/PrathamKSrivastav/ExploreMate.git
   cd ExploreMate
2. Open the project in QT Creator
3. Configure the built settings
4. Build and run the application

---

## Usage
1. Launch the application
2. Select the starting location and input travel parameters (e.g., total days).
3. View optimized routes along with three alternative suggestions.
4. Provide feedback for destinations through the feedback form.

---

## Core Functions
### `suggestPath`
Generates the best route based on:
- Remaining travel days
- Graph parameters (distance, duration, rating, connectivity).
Example Output
```
Dehradun --> Rishikesh --> Chakrata --> Mussoorie

```

### `suggestAlternativeRoute`
Generates three alternative routes based on:
- Remaining travel days
- Graph parameters (distance, duration, rating, connectivity).
Example Output
```
Route 1: Dehradun -> Rishikesh -> Haridwar
Route 2: Dehradun -> Mussoorie -> Chakrata
Route 3: Dehradun -> Tehri -> Dhanaulti
```

---

## Code Highlights
**QString Output Generation**
This function converts a vector of strings representing a travel path into a readable QString format:
```
QString pathString;
for (size_t i = 0; i < suggestedPath.size(); ++i) {
    pathString.append(QString::fromStdString(suggestedPath[i]));
    if (i < suggestedPath.size() - 1) {
        pathString.append(" -> ");
    }
}
```

**Alternate Routes Handling**
Alternative routes (`route1`, `route2`, `route3`) are generated with the following logic:
```
void suggestAlternativeRoutes(const string &currentLocation, float totalDays, vector<string> &route1, vector<string> &route2, vector<string> &route3) {
    // Implementation ensures three routes are generated based on remaining days and graph traversal.
}
```

**Qt UI Integration**
The Qt Widget interface facilitates the following:
- Dropdown for selecting the starting location.
- Buttons for generating routes and submitting feedback.

---

## Future Enhancement
- Integration with Maps API for real-world route suggestions.
- Advanced Budget Optimization considering accommodation and meal costs.
- Enhanced UI with interactive maps and graphical route displays.

---
