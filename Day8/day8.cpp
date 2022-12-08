#include <bits/stdc++.h>

using namespace std;

int main()
{

    ifstream myfile("sample.txt");

    string line;

    vector<vector<int>> v = {};
    while (getline(myfile, line))
    {
        vector<int> temp;
        for (int i = 0; i < line.size(); i++)
        {
            temp.push_back(line[i] - '0');
        }
        
        v.push_back(temp);
    }

    int visibleTrees = 0;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            // count edge tree
            if(i == 0 || i == v.size()-1 || j == 0 || j == v[i].size()-1)
            {
                visibleTrees++;
                // cout << "\e[0;32m Found edge tree at (" << i << ", " << j << ") \e[0;37m" << endl;
                continue;
            }

            int current = v[i][j];
            bool vertUpVisible = true;
            bool vertDownVisible = true;
            bool horLeftVisible = true;
            bool horRightVisible = true;
            // count middle trees
            
            
        }
    }

    cout << "Visible trees: " << visibleTrees;

}