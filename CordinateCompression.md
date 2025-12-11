# CordinateCompression c++

- it is a technique used to reduce the range of coordinates while preserving their relative order.
- it is useful in scenarios where the original coordinates are large or sparse, making it difficult to work with them directly.
- it is commonly used in competitive programming and computational geometry to optimize algorithms that

```cpp 
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> coordinateCompression(const vector<int>& coords) {
    vector<int> sortedCoords = coords; // Copy original coordinates
    sort(sortedCoords.begin(), sortedCoords.end()); // Sort the coordinates
    sortedCoords.erase(unique(sortedCoords.begin(), sortedCoords.end()), sortedCoords.end()); // Remove duplicates

    map<int, int> coordMap; // Map to store compressed coordinates
    for (size_t i = 0; i < sortedCoords.size(); ++i) {
        coordMap[sortedCoords[i]] = i; // Assign compressed value
    }

    vector<int> compressedCoords; // Vector to store compressed coordinates
    for (const int& coord : coords) {
        compressedCoords.push_back(coordMap[coord]); // Get compressed value
    }

    return compressedCoords;
}
```



