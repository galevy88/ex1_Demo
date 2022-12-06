#include "header.h"

using namespace std;


vector< pair<double, int> > bubbleSort(vector< pair<double, int> > v) {
  for (int i = 0; i < v.size() - 1; i++) {
    for (int j = 0; j < v.size() - 1 - i; j++) {
      if (v[j].first > v[j + 1].first) {
        // Swap v[j] and v[j + 1]
        pair<double, int> temp = v[j];
        v[j] = v[j + 1];
        v[j + 1] = temp;
      }
    }
  }
  return v;
}

// Find k nearest neighbors of point sample
int KNN(vector< vector<double> > x_train, vector<int> y_train, vector<double> sample, int k, string func) {
    vector< pair<double, int> > distances;
    int vec_size = x_train.size();

    // Calculate distances between point sample and all x_train in x_train
    for (int i = 0; i < x_train.size(); i++) {

        double distance = 0;

        if(func == "AUC") { distance = euclidian_distance_function(sample, x_train[i]); }
        if(func == "MAN") { distance = manheten_distance_function(sample, x_train[i]); }
        if(func == "CHB") { distance = chebyshev_distance_function(sample, x_train[i]); }
        if(func == "CAN") { distance = canberra_distance_function(sample, x_train[i]); }
        if(func == "MIN") { distance = minkowski_distance_function(sample, x_train[i]); }
        distances.push_back(make_pair(distance, i));
    }
    

    vector< pair<double, int> > sorted;
    sorted = bubbleSort(distances);

    
    // Take the first k distances
    vector<int> neighbors;
    for (int i = 0; i < k; i++) { 
        neighbors.push_back(sorted[i].second); 
    }
    
     for (int i =0; i < neighbors.size(); i++) {
       cout << neighbors[i] << " ";
     }
     
    int monim[y_train.size()] = {};
    for (int i = 0; i < neighbors.size(); i++) {
        monim[y_train[neighbors[i]]]++; 
    }
    // for (int i = 0; i < 3; i++) {
    //     cout << i << " " << monim[i] << "\n"; 
    // }
    int imax = 0;
    int max = 0;
    for (int i = 0; i < y_train.size(); i++) {
        if (monim[i] > max) { max = monim[i]; imax = i; }
    }

    return imax;
}

// int main() {
//   // Define x_train
//   vector< vector<double> > x_train = {
//     {1, 1},
//     {1, 2},
//     {2, 1},
//     {2, 2},
//     {3, 3},
//     {4, 5},
//     {5, 4},
//     {5, 5}
//   };
//   vector<int> y_train = {0 , 1, 0, 2, 2, 1, 2, 0};
//   // Define point to classify
//   vector<double> sample = {1, 0};

//   // Find k nearest neighbors
//   int k = 3;
//   string func = "AUC";
//   int imax = KNN(x_train, y_train, sample, k, func);
//   cout << "The Most fluent label is: " << imax; 


//   return 0;
// }
