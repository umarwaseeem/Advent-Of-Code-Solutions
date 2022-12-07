import os
import aocd
import requests


# make a cpp template code which opens a file named input.txt and reads the input from it
cppTemplate = """#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    
    ifstream myfile ("input.txt");
    
    if(myfile.is_open())
    {
        while(getline(myfile,line))
        {
            cout << line << endl;
        }
        myfile.close();
    }
    else
    {cout << "Unable to open file";} 
    
    return 0;
}
"""


# make a python template code which opens a file named input.txt and reads the input from it
pythonTemplate = """import os
file = open("input.txt", "r")

for line in file:
    print(line)

    file.close()
"""

day = input("Enter the day: ")
year = input("Enter the year: ")

try:
    data = aocd.get_data(day=int(day), year=int(year))
except:
    print("Error: Invalid day or year")
    exit()
    

path = str(os.getcwd()) + "/Day " + day

try:
    os.mkdir(path)
except:
    print("Error in making directory")
    exit()

os.system(""" aoc download -d {day} -y {year} -i "Day{day}/input.txt" -p "Day{day}/puzzle.md"  """.format(day=day, year=year))

lang = input("Enter the language for solution: ")

if lang == "cpp":
    try:
        f = open(path + "/day" + day +  ".cpp", "w")
        f.write(cppTemplate)
        f.close()
    except:
        print("Error in writing to file")
        exit()
elif lang == "py":
    try:
        f = open(path + "/day" + day +  ".py", "w")
        f.write(pythonTemplate)
        f.close()
    except:
        print("Error in writing to file")
        exit()
else:
    # open file with extension of the language
    try:
        f = open(path + "/day" + day +  "." + lang, "w")
        f.close()
    except:
        print("Error in writing to file")
        exit()

print("Done")

