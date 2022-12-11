#include <string>
#include <string.h>
#include <iostream>
#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <list>
#include <functional>

using namespace std;

// KNN moudle functions
vector< pair<double, int> > bubbleSort(vector< pair<double, int> > v, int size);
int KNN(vector< vector<double> > x_train, vector<int> y_train, vector<double> sample, int k, string func, int labels_number);

// Calculator moudle functions
double euclidian_distance_function(vector<double> vec1, vector<double> vec2);
double manheten_distance_function(vector<double> vec1, vector<double> vec2);
double chebyshev_distance_function(vector<double> vec1, vector<double> vec2);
double canberra_distance_function(vector<double> vec1, vector<double> vec2);
double minkowski_distance_function(vector<double> vec1, vector<double> vec2);

// main moudle functions
void check_size(int size, string csv_type);
void check_args(int size, string csv_type, string dist_func);
string fetch_path(string input);
vector<double> parser(string string_Vector);
string get_label_classify(int label);
void print_vec(vector<vector<double> > x_train);
int get_labels_number(string csv_type);


