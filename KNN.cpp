#include "header.h"



KNN::KNN(function<double(vector<double>, vector<double>)> distance_metric, int k) {
    this->distance_metric = distance_metric;
    this->k = k;
}