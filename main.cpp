#include <string>
#include <iostream>
#include <math.h>
using namespace std;



int input_check(string vec1_input, string vec2_input) {
    int size_vec_1 = vec1_input.length();
    int size_vec_2 = vec2_input.length();

    if(size_vec_1 != size_vec_2) {
        cout << "Invalid Input - Vector Must Be Equal";
        return -1;
    }
    return 0;
}


float euclidian_distance_function(int* vec1, int* vec2, int array_size) {
    float sum = 0.0;
    for(int i = 0; i < array_size; i++) {
        sum += pow(vec1[i]-vec2[i], 2);
    }
    return sqrt(sum);
}

float manheten_distance_function(int* vec1, int* vec2, int array_size) {
    float sum = 0.0;
    for(int i = 0; i < array_size; i++) {
        sum += abs(vec1[i]-vec2[i]);
    }
    return sum;
}

float chebyshev_distance_function(int* vec1, int* vec2, int array_size) {
    float max = 0.0;
    for(int i = 0; i < array_size; i++) {
        float z = abs(vec1[i]-vec2[i]);
        if(z > max){ max = z;}
    }
    return max;
}

float canberra_distance_function(int* vec1, int* vec2, int array_size) {
    float sum = 0.0;
    for(int i = 0; i < array_size; i++) {
        float nome = abs(vec1[i]-vec2[i]);
        float denome = abs(vec1[i]) + abs(vec2[i]);
        sum += nome / denome;
    }
    return sum;
}

float minkowski_distance_function(int* vec1, int* vec2, int array_size) {
    float sum = 0.0;
    for(int i = 0; i < array_size; i++) {
        float z = abs(vec1[i]-vec2[i]);
        sum += pow(z, array_size);
    }
    return pow(sum, 1/array_size);
}

int main()
{
    string vec1_input, vec2_input;
    getline(cin, vec1_input);
    getline(cin, vec2_input);
    if(input_check(vec1_input, vec2_input) == -1) { return -1; }

    int size_vec_1 = vec1_input.length();
    int array_size = (size_vec_1 / 2) + 1;
    int* vec1 = new int[array_size]; int* holder1 = vec1;
    int* vec2 = new int[array_size]; int* holder2 = vec2;
    

    for(int i = 0; i < size_vec_1; i++) {
        if(i%2 == 0) {
            *vec1 = int(vec1_input[i]) - 48; vec1++;
            *vec2 = int(vec2_input[i]) - 48; vec2++;
        }
    }
    vec1 = holder1; vec2 = holder2;

    float euclidian_distance = euclidian_distance_function(vec1, vec2, array_size);
    float manheten_distance = manheten_distance_function(vec1, vec2, array_size);
    float chebyshev_distance = chebyshev_distance_function(vec1, vec2, array_size);
    float canberra_distance = canberra_distance_function(vec1, vec2, array_size);
    float minkowski_distance = minkowski_distance_function(vec1, vec2, array_size);
    cout << euclidian_distance << "\n";
    cout << manheten_distance << "\n";
    cout << chebyshev_distance << "\n";
    cout << canberra_distance << "\n";
    cout << minkowski_distance << "\n";
}