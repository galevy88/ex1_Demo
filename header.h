#include <string>
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
    list< vector<double> > x_train;
    list<int> y_train;
    vector<double> parser(string string_Vector, int stop_idx);
    string reverse(string str);
    int get_label_number(string label);
    void create_split(string line, vector<double>& vec, int& label_num);
    
    public:
    Data(const string path);
    void generate_data();
    list<vector<double>> get_x_train();
    list<int> get_y_train();
};


class KNN {
    private:
    function<double(vector<double>, vector<double>)> distance_metric;
    int k;
    KNN(function<double(vector<double>, vector<double>)> distance_metric, int k);
};

void euclidian_distance_function(vector<double> vec1, vector<double> vec2, int array_size);
void manheten_distance_function(vector<double> vec1, vector<double> vec2, int array_size);
void chebyshev_distance_function(vector<double> vec1, vector<double> vec2, int array_size);
void canberra_distance_function(vector<double> vec1, vector<double> vec2, int array_size);
void minkowski_distance_function(vector<double> vec1, vector<double> vec2, int array_size);
