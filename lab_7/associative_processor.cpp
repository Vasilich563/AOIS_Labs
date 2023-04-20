//Author: Vodohleb04
#include "associative_processor.h"

using namespace std;

vector<vector<int>> makeRandomMatrix(int strings_amount, int strings_length)
{
    if(strings_amount < 1)
    {
        throw invalid_argument("Amount of strings of matrix must be greater then 0");
    }
    else if(strings_length < 1)
    {
        throw invalid_argument("Amount of strings of matrix must be greater then 0");
    }
    srand(time(NULL));
    vector<vector<int>> matrix(strings_amount);
    for(int i = 0; i < strings_amount; i++)
    {
        for(int j = 0; j < strings_length; j++)
        {
            matrix[i].push_back(rand() % 2);
        }
    }
    return matrix;
}

ostream& operator<<(ostream& out, vector<vector<int>> int_matrix)
{
    for(auto matrix_string : int_matrix)
    {
        for(auto number : matrix_string)
        {
            out << number << " ";
        }
        out << "\n";
    }

    return out;
}