#include <iostream>
#include <vector>
#include <map>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int numFacesPerDie = 6;
    int totalCombinations = numFacesPerDie * numFacesPerDie;
    cout << "Total combinations: " << totalCombinations << endl;
   vector<std::vector<int>> combinationsMatrix(numFacesPerDie, std::vector<int>(numFacesPerDie));

   for (int i = 0; i < numFacesPerDie; i++) {
       for (int j = 0; j < numFacesPerDie; j++) {
           combinationsMatrix[i][j] = i + j + 2; //since sum from 2 to 12
       }
   }
   cout<<"\n";
   cout << "Distribution of all possible combinations:\n";
   for (const auto& row : combinationsMatrix) {
       for (int value : row) {
           cout << value << " ";
       }
       cout << endl;
   }

  map<int, int> sumCounts;  // Map to store the count of each sum

  // Count occurrences of each sum
  for (int i = 0; i < numFacesPerDie; i++) {
      for (int j = 0; j < numFacesPerDie; j++) {
          int sumValue = combinationsMatrix[i][j];
          sumCounts[sumValue]++;
      }
  }

  // Calculate probabilities
  cout<<"\n";
  cout << "Probability of each possible sum:\n";
  for (const auto& pair : sumCounts) {
      double probability = static_cast<double>(pair.second) / totalCombinations;
      cout << pair.first << ": " << probability << endl;
  }
}


