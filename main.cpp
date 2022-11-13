#include <string>
#include <iomanip>
#include <iostream>
#include <math.h>
#include "Calculator.cpp"

using namespace std;

int input_check(string vec1_input, string vec2_input) {
    int size_vec_1 = vec1_input.length();
    int size_vec_2 = vec2_input.length();

    if(size_vec_1 != size_vec_2) {
        cout << "Invalid Input - Vectors Size Must Be Equal";
        return -1;
    }
    return 0;
}

int main()
{
    std::cout << std::setprecision(15);
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

    Calculator calculator;
    cout << calculator.euclidian_distance_function(vec1, vec2, array_size) << "\n";
    cout << calculator.manheten_distance_function(vec1, vec2, array_size) << "\n";
    cout << calculator.chebyshev_distance_function(vec1, vec2, array_size) << "\n";
    cout << calculator.canberra_distance_function(vec1, vec2, array_size) << "\n";
    cout << calculator.minkowski_distance_function(vec1, vec2, array_size) << "\n";
}