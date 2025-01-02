#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int processQueries(int n, int m, vector<pair<int, int>> queries) {
    unordered_map<int, int> rowToggle, colToggle;
    for (auto query : queries) {
        int x = query.first;
        int y = query.second;
        rowToggle[x]++;
        colToggle[y]++;
    }

    int oddRows = 0, oddCols = 0;
    for (auto row : rowToggle) {
        if (row.second % 2 != 0) {
            oddRows++;
        }
    }

    for (auto col : colToggle) {
        if (col.second % 2 != 0) {
            oddCols++;
        }
    }

    int totalOddCells = (oddRows * m) + (oddCols * n) - (2 * oddRows * oddCols);
    return totalOddCells;
}

int main() {
    
    int n = 4, m = 5;
    vector<pair<int, int>> queries = { {1, 2}, {2, 3}, {4, 5}, {1, 5}, {3, 3}, {4, 2} };

    int result = processQueries(n, m, queries);
    cout << "Number of toggle element is: " << result<<endl;

    return 0;
}
