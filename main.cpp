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

int get_label_number(string label) {
    
    if(label == "Iris-setosa") { return 0; }
    if(label == "Iris-versicolor") { return 1; }
    if(label == "Iris-virginica") { return 2; }

    if(label == "red wine") { return 0; }
    if(label == "white wine") { return 1; }
    if(label == "Sparkling wine") { return 2; }

    if(label == "SEKER") { return 0; }
    if(label == "BARBUNYA") { return 1; }
    if(label == "BOMBAY") { return 2; }
    if(label == "CALI") { return 3; }
    if(label == "HOROZ") { return 4; }
    if(label == "SIRA") { return 5; }
    if(label == "DERMASON") { return 6; }
    
    return -1;
}

//Getting input from the client and fetching the results to the disnaces functions
int main(int argc, char* argv[])
{
    string vec_input;
    getline(cin, vec_input);
    vector<double> vec = parser(vec_input);    
    int vec_size = vec.size();

    int k = atoi(argv[1]);
    string csv_type = argv[2];
    string distance_function = argv[3];

    string iris_str; string beans_str; string wine_str;
    string chosen;
    if(csv_type == "iris_classified.csv") {
        iris_str = "iris\\" + csv_type;
        chosen = iris_str;
    }
    
    if(csv_type == "beans_classified.csv") {
        beans_str = "beans\\" + csv_type;
        chosen = beans_str;
    }

   if(csv_type == "wine_classified.csv") {
        wine_str = "wine\\" + csv_type;
        chosen = wine_str;
    }


    Data d(chosen);
    d.generate_data();
    vector<vector<double>> x_train = d.get_x_train();
    vector<int> y_train = d.get_y_train();
    
    int imax = KNN(x_train, y_train, vec, k, distance_function);
    cout << "The classification is: " << imax;
}