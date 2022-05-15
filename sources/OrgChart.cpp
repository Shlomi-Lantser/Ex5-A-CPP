#include <string>
#include <vector>
#include "Node.hpp"
#include "OrgChart.hpp"
#include <iostream>
#include <unordered_map>

using namespace std;

namespace ariel
{

    OrgChart::OrgChart()
    {
        this->root = nullptr;
        this->size = 0;
    };
    OrgChart::~OrgChart(){};
    OrgChart &OrgChart::add_root(const string &role)
    {
        this->root = new Node(role);
        this->size++;
        return *this;
    }

    int OrgChart::getIndex(Node &node) const
    {
        int result = 0;
        if (node.getParent() != this->root){
        for (Node *children : node.getParent()->getParent()->children)
        {
            if (children == node.getParent())
            {
                break;
            }
            result++;
        }
        }
        return result;
    }

    Node *OrgChart::getRoot()
    {
        return this->root;
    }

    Node *findNode(string name, Node *root)
    {
        if (root->getRole() == name)
        {
            return root;
        }
        for (uint i = 0; i < root->children.size(); i++)
        {
            Node *node = findNode(name, root->children[i]);
            if (node != nullptr)
            {
                return node;
            }
        }
        return nullptr;
    }

    OrgChart &OrgChart::add_sub(const string &parent, const string &child)
    {
        Node *parentNode = findNode(parent, root);
        if (parentNode == nullptr)
        {
            throw "Parent does not exist";
        }
        Node *childNode = new Node(child);
        parentNode->children.push_back(childNode);
        childNode->parent = parentNode;
        this->size++;
        return *this;
    }

    void level_order_helper(Node *node, int level, unordered_map<int, vector<Node *>> &map)
    {
        if (node == nullptr)
        {
            return;
        }
        map[level].push_back(node);
        for (uint i = 0; i < node->children.size(); i++)
        {
            level_order_helper(node->children[i], level + 1, map);
        }
    }

    void pre_order_helper(Node *node, vector<Node *> &vec)
    {
        if (node == nullptr)
        {
            return;
        }
        vec.push_back(node);
        for (uint i = 0; i < node->children.size(); i++)
        {
            pre_order_helper(node->children[i], vec);
        }
    }

    ostream &operator<<(ostream &os, const OrgChart &org)
    {
        unordered_map<int, vector<Node *>> map;
        Node *root = org.root;
        level_order_helper(root, 0, map);
        string tempJ;

        for (int i = 0; map[i].size() > 0; i++)
        {
            tempJ = "";
            for (Node *j : map[i])
            {
                Node *node = findNode(j->getRole(), org.root);
                if (node == org.root){
                    int size = org.size;
                    for (int i = 0; i < size*5/2; i++)
                    {
                        os << " ";
                    }
                    os << node->getRole();
                }
                else if (node->children.size() > 1)
                {
                    for (int k = 0; k < (node->children.size() + 1 / 2) * 5; k++)
                    {
                        os << " ";
                    }
                    os << j->getRole();
                }
                else if (node->getParent() == org.root)
                {
                    os << "     " << j->getRole();
                }

                else
                {
                    if (node == node->parent->children[0]){
                        int parentIndex = org.getIndex(*node);
                        if (parentIndex ==0){
                            parentIndex++;
                        }
                        for (int k = 0; k < (parentIndex * 5) - parentIndex; k++)
                        {
                            os << " ";
                        }
                    }
                    os << " " << j->getRole();
                }
            }
            os << endl;
        }
        return os;
    }

    OrgChart::Iterator::Iterator()
    {
        current = nullptr;
        flag = "default"; // level_order
    }

    OrgChart::Iterator::Iterator(Node *root)
    {
        this->current = root;
        flag = "default"; // level_order
    }

    OrgChart::Iterator::Iterator(Node *root, string flag)
    {
        this->current = root;
        this->flag = flag;

        if (flag == "defualt")
        { // level_order
            unordered_map<int, vector<Node *>> map;
            level_order_helper(root, 0, map);

            for (int i = 0; map[i].size() > 0; i++)
            {
                for (Node *j : map[i])
                {
                    this->def_queue.push(j);
                }
            }
        }else if (flag == "reverse_level"){
            unordered_map<int, vector<Node *>> map;
            level_order_helper(root, 0, map);

            for (int i=0 ; map[i].size() > 0 ; i++){
                for (Node *j : map[i]){
                    this->reverse_def.push(j);
                }
            }
            while (!this->reverse_def.empty())
            {
                this->def_queue.push(this->reverse_def.top());
                this->reverse_def.pop();
            }
        }else if (flag == "pre_order"){
            vector<Node *> vec;
            pre_order_helper(root, vec);
            for (Node *j : vec){
                this->def_queue.push(j);
            }
        }
    }

    bool OrgChart::Iterator::operator==(const Iterator &other) const
    {
        return this->current == other.current;
    }

    bool OrgChart::Iterator::operator!=(const Iterator &other) const
    {
        if (this->def_queue.empty()){
            return false;
        }
        return !(*this == other);
    }

    OrgChart::Iterator &OrgChart::Iterator::operator++()
    {
        if (!def_queue.empty())
        {
            def_queue.pop();
        }
        else
        {
            *this = OrgChart::Iterator(nullptr);
        }
        return *this;
    }

    string OrgChart::Iterator::operator*()
    {
        return def_queue.front()->getRole();
    }

    string *OrgChart::Iterator::operator->(){
        return &def_queue.front()->role;
    }

    OrgChart::Iterator OrgChart::begin_level_order() { return OrgChart::Iterator(this->root, "defualt"); }

    OrgChart::Iterator OrgChart::end_level_order() { return OrgChart::Iterator(nullptr); }

    OrgChart::Iterator OrgChart::reverse_order() { return OrgChart::Iterator(nullptr); }

    OrgChart::Iterator OrgChart::begin_preorder() { return OrgChart::Iterator(this->root, "pre_order"); }

    OrgChart::Iterator OrgChart::end_preorder() { return OrgChart::Iterator(nullptr); }

    OrgChart::Iterator OrgChart::begin_reverse_order() { return OrgChart::Iterator(this->root, "reverse_level"); }

    OrgChart::Iterator OrgChart::begin() { return OrgChart::Iterator(this->root, "defualt"); }

    OrgChart::Iterator OrgChart::end() { return OrgChart::Iterator(nullptr); }

    void initHelper_leve(Node *node, queue<Node *> &q)
    {
        if (node == nullptr)
        {
            return;
        }
        q.push(node);
        for (uint i = 0; i < node->children.size(); i++)
        {
            initHelper_leve(node->children[i], q);
        }
    }
}