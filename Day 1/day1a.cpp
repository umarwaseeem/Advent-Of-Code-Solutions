#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> inputCalories;

    int calories = 0;
    int sum = 0;
    
    while(cin >> calories){
        
        sum += calories;

        if(cin.get() == '\n' || cin.eof()){
            // second new line means calories of one elf are done
            if(cin.get() == '\n' || cin.eof()){
                inputCalories.push_back(sum);
                sum = 0;
            }
            else{
                cin.unget();
            }
        }
    }

    // part (a)
    // int maxCalories = *max_element(inputCalories.begin(), inputCalories.end());

    // part (b)
    // find top 3 max calories
    sort(inputCalories.begin(), inputCalories.end(), greater<int>());
    int maxCalories = 0;
    for (int i = 0; i < 3; i++)
    {
        maxCalories += inputCalories[i];
    }

    cout << maxCalories << endl;
}