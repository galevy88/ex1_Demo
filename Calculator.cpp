#include "header.h"
using namespace std;

//A function that print the calculation result as a double type
void print_answer_as_double(double answer) {
    fixed(cout);
    //if the answer is an intiger - print one digit after the point:
    if (int(answer) == answer) {
        cout.precision(1);
        cout << answer << endl;
    }
    //And if the result is a double  - print one digit after the point:
    else{
        cout.precision(4);
        cout << answer << endl;
    }
}

//A function that calculate the distance between two vectors by using the euclidean distance algorithm:
void euclidian_distance_function(vector<double> vec1, vector<double> vec2, int vec_size) {
    double sum = 0.0;
    for(int i = 0; i < vec_size; i++) {
        sum += pow(vec1[i]-vec2[i], 2);
    }
    print_answer_as_double(sqrt(sum));
}

//A function that calculate the distance between two vectors by using the manheten distance algorithm:
void manheten_distance_function(vector<double> vec1, vector<double> vec2, int vec_size) {
    double sum = 0.0;
    for(int i = 0; i < vec_size; i++) {
        sum += abs(vec1[i]-vec2[i]);
    }
    print_answer_as_double(sum);
}

//A function that calculate the distance between two vectors by using the chebyshev distance algorithm:
void chebyshev_distance_function(vector<double> vec1, vector<double> vec2, int vec_size) {
    double max = 0.0;
    for(int i = 0; i < vec_size; i++) {
        double z = abs(vec1[i]-vec2[i]);
        if(z > max){ max = z;}
    }
    print_answer_as_double(max);
}

//A function that calculate the distance between two vectors by using the canberra distance algorithm:
void canberra_distance_function(vector<double> vec1, vector<double> vec2, int vec_size) {
    double sum = 0.0;
    for(int i = 0; i < vec_size; i++) {
        double nome = abs(vec1[i]-vec2[i]);
        double denome = abs(vec1[i]) + abs(vec2[i]);
        sum += nome / denome;
    }
    print_answer_as_double(sum);
}
//A function that calculate the distance between two vectors by using the minkowski distance algorithm:
void minkowski_distance_function(vector<double> vec1, vector<double> vec2, int vec_size) {
    double sum = 0.0;
    for(int i = 0; i < vec_size; i++) {
        double z = abs(vec1[i]-vec2[i]);
        sum += pow(z, 2);
    }
    print_answer_as_double(pow(sum, 0.5));
}
