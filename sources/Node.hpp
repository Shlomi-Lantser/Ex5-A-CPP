#include <string>
#include <vector>

using namespace std;

#pragma once
namespace ariel
{
    class Node
    {
    public:
        Node(const string &name);
        ~Node();
        string getRole() const;
        vector<Node *> children;
        Node *getParent();
        Node *parent;
        string role;
    private:
        int size;
    };
}