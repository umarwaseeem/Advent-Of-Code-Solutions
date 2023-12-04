#include <bits/stdc++.h>

using namespace std;

void firstPart(int min1, int max1, int min2, int max2, int score){
    if(min1 <= min2 && max1 >= max2 || min2 <= min1 && max2 >= max1){
        score++;
    }
}

void secondPart(int min1, int max1, int min2, int max2, int score){
    if(min1 <= max2 && min2 <= max1){
        score++;
    }
}

int main(){

    string input;

    int score = 0;

    while(getline(cin,input)){

        string part1 = input.substr(0,input.find(","));
        string part2 = input.substr(input.find(",")+1);

        int min1 = stoi(part1.substr(0,part1.find("-")));
        int max1 = stoi(part1.substr(part1.find("-")+1));

        int min2 = stoi(part2.substr(0,part2.find("-")));
        int max2 = stoi(part2.substr(part2.find("-")+1));

        firstPart(min1, max1, min2, max2, score);
        secondPart(min1, max1, min2, max2, score);
    }

    cout << score << endl;
}