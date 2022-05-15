#include <string>
#include <vector>
#include "Node.hpp"
#include "iterator.hpp"
#include <stack>
#include <queue>


using namespace std;

namespace ariel
{
    class OrgChart
    {

        class Iterator
        {
            private:
                Node *current;
                queue<Node *> def_queue;
                stack<Node *> reverse_def;

            public:
                Iterator();
                Iterator(Node *root);
                Iterator(Node *root, string flag);
                Iterator &operator++();
                bool operator==(const Iterator &other) const;
                bool operator!=(const Iterator &other) const;
                string operator*();
                string *operator->();
                void initialize();
                string flag;


        };

    public:
        OrgChart();
        ~OrgChart();
        OrgChart &add_root(const string &role);
        OrgChart &add_sub(const string &parent,const string &child);
        Node *getRoot();
        int size;
        friend ostream &operator<<(ostream &os, const OrgChart &org);
        int getIndex(Node &node) const ;
        Iterator begin();
        Iterator end();
        Iterator begin_level_order();
        Iterator end_level_order();
        Iterator begin_reverse_order();
        Iterator reverse_order();
        Iterator begin_preorder();
        Iterator end_preorder();

    private:
        Node *root;
        // vector<Node *> nodes;
    };
}