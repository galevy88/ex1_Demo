#include <iostream>
#include <math.h>
#include "header.h"


float Calculator::euclidian_distance_function(int* vec1, int* vec2, int array_size) {
    float sum = 0.0;
    for(int i = 0; i < array_size; i++) {
        sum += pow(vec1[i]-vec2[i], 2);
    }
    return sqrt(sum);
}

float Calculator::manheten_distance_function(int* vec1, int* vec2, int array_size) {
    float sum = 0.0;
    for(int i = 0; i < array_size; i++) {
        sum += abs(vec1[i]-vec2[i]);
    }
    return sum;
}

float Calculator::chebyshev_distance_function(int* vec1, int* vec2, int array_size) {
    float max = 0.0;
    for(int i = 0; i < array_size; i++) {
        float z = abs(vec1[i]-vec2[i]);
        if(z > max){ max = z;}
    }
    return max;
}

float Calculator::canberra_distance_function(int* vec1, int* vec2, int array_size) {
    float sum = 0.0;
    for(int i = 0; i < array_size; i++) {
        float nome = abs(vec1[i]-vec2[i]);
        float denome = abs(vec1[i]) + abs(vec2[i]);
        sum += nome / denome;
    }
    return sum;
}

float Calculator::minkowski_distance_function(int* vec1, int* vec2, int array_size) {
    float sum = 0.0;
    for(int i = 0; i < array_size; i++) {
        float z = abs(vec1[i]-vec2[i]);
        sum += pow(z, 2);
    }
    return pow(sum, 0.5);
}