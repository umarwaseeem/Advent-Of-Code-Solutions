#include <bits/stdc++.h>
using namespace std;

int maxUsed = 70000000 - 30000000;

struct Node
{
    int size;
    string directory;
    Node *parent;
    vector<Node *> children;
};

class FileSystem
{
public:
    Node *rootDir;
    Node *currentDir;
    string currentPath;

    FileSystem()
    {
        rootDir = new Node();
        rootDir->size = 0;
        rootDir->directory = "/";
        rootDir->parent = NULL;
    }

    void cd(string dir)
    {

        for (int i = 0; i < currentDir->children.size(); i++)
        {
            if (currentDir->children[i]->directory == dir)
            {
                currentDir = currentDir->children[i];
                break;
            }
        }
    }

    void cdBack()
    {
        if (currentDir->parent != NULL)
        {
            currentDir = currentDir->parent;
        }
    }

    void cdRoot()
    {
        currentDir = rootDir;
    }

    void mkdir(Node *newDir)
    {
        if (rootDir == NULL)
        {
            rootDir = newDir;
        }
        else
        {
            currentDir->children.push_back(newDir);
            newDir->parent = currentDir;
        }
    }

    void adjustSize(int size)
    {

        currentDir->size += size;
        Node *temp = currentDir;
        while (temp->parent != NULL)
        {
            temp->parent->size += size;
            temp = temp->parent;
        }
    }

    void printFileTree()
    {

        cout << "File Tree: " << endl;
        printFileTreeHelper(rootDir);
    }

    void printFileTreeHelper(Node *node)
    {
        cout << node->directory << " " << node->size << endl;
        for (int i = 0; i < node->children.size(); i++)
        {
            printFileTreeHelper(node->children[i]);
        }
    }

    void solve1()
    {
        int sum = 0;

        solve1Helper(rootDir, sum);

        cout << "Sum: " << sum << endl;
    }

    void solve1Helper(Node *node, int &sum)
    {
        if (node->size <= 100000)
        {
            sum += node->size;
        }
        for (int i = 0; i < node->children.size(); i++)
        {
            solve1Helper(node->children[i], sum);
        }
    }

    void solve2()
    {
        int totalSize = rootDir->size;

        int dirSize = totalSize - maxUsed;

        int minSize = solve2Helper(rootDir, dirSize);
        cout << "Min Size: " << minSize << endl;
    }

    int solve2Helper(Node *node, int dirSize)
    {
        int minSize = INT_MAX;
        if (node->size >= dirSize)
        {
            minSize = node->size;
        }
        for (int i = 0; i < node->children.size(); i++)
        {
            int temp = solve2Helper(node->children[i], dirSize);
            if (temp < minSize)
            {
                minSize = temp;
            }
        }
        return minSize;
    }
};

vector<string> tokenize(string str)
{

    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, ' '))
    {
        tokens.push_back(token);
    }

    return tokens;
}

int main()
{

    ifstream myfile("input.txt");

    string command;

    string line;

    FileSystem fs = FileSystem();

    while (getline(myfile, line))
    {

        vector<string> theLine = tokenize(line);

        if (theLine[1] == "cd")
        {
            if (theLine[2] == "/")
            {
                fs.cdRoot();
            }
            else if (theLine[2] == "..")
            {
                fs.cdBack();
            }
            else
            {
                fs.cd(theLine[2]);
            }
        }
        else if (theLine[1] == "ls")
        {
            continue;
        }
        else if (theLine[0] == "dir")
        {
            Node *newDir = new Node();
            newDir->directory = theLine[1];
            fs.mkdir(newDir);
        }
        else
        {
            int size = stoi(theLine[0]);
            fs.adjustSize(size);
        }
    }

    fs.solve1();
    fs.solve2();

    return 0;
}
