#include <string>
#include <vector>
#include "Node.hpp"

using namespace std;

namespace ariel{
    Node::Node(const string &role){
        this->role = role;
        this->children = vector<Node *>();
        this->parent = nullptr;
    }
    Node::~Node(){
        for(uint i = 0; i < this->children.size(); i++){
            delete this->children[i];
        }
    }
    string Node::getRole() const{
        return this->role;
    }

    Node* Node::getParent(){
        return this->parent;
    }
    
}