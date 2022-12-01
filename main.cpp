#include "header.h"

using namespace std;
// Check either the vectors are with the sae ssize or not
void check_size(int size1, int size2) {
    if(size1 != size2) {
        cout << "Invalid Input - Please Refer To README.md File And Try Again :)"; exit(0);
    }
}

// Parsing the input which got as string into a vector with double type variabls
vector<double> parser(string string_Vector) {
    vector<double> Vector;
    string current;

    for(int i = 0; i <= string_Vector.length(); i++)
    {
        if(string_Vector[i] == ' ' || string_Vector[i] == '\0') 
        {
            try { Vector.push_back(stod(current)); current = ""; } 
            catch (...) { cout << "Invalid Input - Please Refer To README.md File And Try Again :)"; exit(0); }
        }
        else { current += string_Vector[i]; }
    }
    return Vector;
}


// Getting input from the client and fetching the results to the disnaces functions
int main()
{
    string vec_input;
    getline(cin, vec_input);

    vector<double> vec = parser(vec_input);
    int vec_size = vec.size();

    string iris_str = "iris\\iris_classified.csv";
    string beans_str = "beans\\beans_Classified.csv";
    string wine_str = "wine\\wine_Classified.csv";
    Data d(beans_str);
    d.generate_data();
    list<vector<double>> x_train = d.get_x_train();
    list<int> y_train = d.get_y_train();
    cout << x_train.size() << " " << y_train.size();
}