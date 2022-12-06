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

class Data {
    private:
    string path;
    vector< vector<double> > x_train;
    vector<int> y_train;
    vector<double> parser(string string_Vector, int stop_idx);
    string reverse(string str);
    int get_label_number(string label);
    void create_split(string line, vector<double>& vec, int& label_num);
    
    public:
    Data(const string path);
    void generate_data();
    vector<vector<double>> get_x_train();
    vector<int> get_y_train();
};

vector< pair<double, int> > bubbleSort(vector< pair<double, int> > v);
int KNN(vector< vector<double> > x_train, vector<int> y_train, vector<double> sample, int k, string func);

double euclidian_distance_function(vector<double> vec1, vector<double> vec2);
double manheten_distance_function(vector<double> vec1, vector<double> vec2);
double chebyshev_distance_function(vector<double> vec1, vector<double> vec2);
double canberra_distance_function(vector<double> vec1, vector<double> vec2);
double minkowski_distance_function(vector<double> vec1, vector<double> vec2);
