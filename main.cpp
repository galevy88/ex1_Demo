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

string get_label_name(int label_num, string file_name) {
    if (file_name == "iris_classified.csv") {
        if(label_num == 0) { return "Iris-setosa"; }
        if(label_num == 1) { return "Iris-versicolor"; }
        if(label_num == 2) { return "Iris-virginica"; }
    }

    if (file_name == "wine_classified.csv") {
            if(label_num == 0) { return "red wine"; }
            if(label_num == 1) { return "white wine"; }
            if(label_num == 2) { return "Sparkling wine"; }
    }

    if (file_name == "beans_classified.csv") {
            if(label_num == 0) { return "SEKER"; }
            if(label_num == 1) { return "BARBUNYA"; }
            if(label_num == 2) { return "BOMBAY"; }
            if(label_num == 3) { return "CALI"; }
            if(label_num == 4) { return "HOROZ"; }
            if(label_num == 5) { return "SIRA"; }
            if(label_num == 6) { return "DERMASON"; }
    }
    return NULL;
}

//Getting input from the client and fetching the results to the disnaces functions
int main(int argc, char** argv)
{
    int k = atoi(argv[1]);
    string file_name = argv[2];
    string distance_method = argv[3];


    string iris_str, beans_str, wine_str, chosen;
    
    if(file_name == "iris_classified.csv") {
        iris_str = "iris\\" + file_name;
        chosen = iris_str;
    }
    
    if(file_name == "beans_classified.csv") {
        beans_str = "beans\\" + file_name;
        chosen = beans_str;
    }

   if(file_name == "wine_classified.csv") {
        wine_str = "wine\\" + file_name;
        chosen = wine_str;
    }


    Data d(chosen);
    d.generate_data();

    vector<vector<double>> x_train = d.get_x_train();
    vector<int> y_train = d.get_y_train();

    string vec_input;
    cout << "Put an unclassified vector: " << endl;
    getline(cin, vec_input);

    // vector<double> sample = {6.4,2.9,4.3,1.3};

    vector<double> vec = parser(vec_input);    

    //int vec_size = vec.size();

    int imax = KNN(x_train, y_train, vec, k, distance_method);
    string classification = get_label_name(imax, file_name);

    cout << "The classification is: " << classification;
}