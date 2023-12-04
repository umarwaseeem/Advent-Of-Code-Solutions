#include <bits/stdc++.h>

using namespace std;

void part1(map<char,int> priorities);
void part2(map<char,int> priorities);

int main()
{

    map<char, int> priorities = {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}, {'h', 8}, {'i', 9}, {'j', 10}, {'k', 11}, {'l', 12}, {'m', 13}, {'n', 14}, {'o', 15}, {'p', 16}, {'q', 17}, {'r', 18}, {'s', 19}, {'t', 20}, {'u', 21}, {'v', 22}, {'w', 23}, {'x', 24}, {'y', 25}, {'z', 26}, {'A', 27}, {'B', 28}, {'C', 29}, {'D', 30}, {'E', 31}, {'F', 32}, {'G', 33}, {'H', 34}, {'I', 35}, {'J', 36}, {'K', 37}, {'L', 38}, {'M', 39}, {'N', 40}, {'O', 41}, {'P', 42}, {'Q', 43}, {'R', 44}, {'S', 45}, {'T', 46}, {'U', 47}, {'V', 48}, {'W', 49}, {'X', 50}, {'Y', 51}, {'Z', 52}};

    // part1(priorities);
    part2(priorities);
}


void part1(map<char,int> priorities)
{
    string inputLine;

    int priorityScore = 0;

    while (getline(cin, inputLine))
    {

        // store first half of input line in a string and second half in a string
        // for example if there are 12 characters in the input line, the first half will be 6 characters and the second half will be 6 characters from the next character
        string firstHalf = inputLine.substr(0, inputLine.length() / 2);
        string secondHalf = inputLine.substr(inputLine.length() / 2, inputLine.length() / 2);

        // find the common letter between the two halfs
        char commonLetter;

        for (int i = 0; i < firstHalf.length(); i++)
        {
            for (int j = 0; j < secondHalf.length(); j++)
            {
                if (firstHalf[i] == secondHalf[j])
                {
                    commonLetter = firstHalf[i];
                }
            }
        }

        priorityScore += priorities[commonLetter];
    }

    cout << priorityScore;
}

void part2(map<char,int> priorities){
    string inputLine;

    int priorityScore = 0;

    while (getline(cin, inputLine))
    {
        string group1 = inputLine;
        
        getline(cin, inputLine);
        string group2 = inputLine;

        getline(cin, inputLine);
        string group3 = inputLine;


        // common letters between group1 and group2 and group3
        char commonLetter;
        
        for (int i = 0; i < group1.length(); i++)
        {
            for (int j = 0; j < group2.length(); j++)
            {
                for (int k = 0; k < group3.length(); k++)
                {
                    if (group1[i] == group2[j] && group2[j] == group3[k])
                    {
                        commonLetter = group1[i];
                    }
                }
            }
        }


        priorityScore += priorities[commonLetter];
    }

    cout << priorityScore;
}