// #include <string>
// #include <vector>
// #include "Node.hpp"

// using namespace std;

// namespace ariel{
//     class iterator{
//     public:
//         iterator(OrgChart *org);
//         ~iterator();
//         iterator begin_level_order();
//         iterator end_level_order();
//         iterator begin_reverse_order();
//         iterator end_reverse_order();
//         iterator begin_preorder();
//         iterator end_preorder();
//         iterator operator++();
//         iterator operator++(int);
//         iterator operator--();
//         iterator operator--(int);
//         Node* operator*();
//         bool operator==(const iterator& other);
//         bool operator!=(const iterator& other);
//         int size();

//     private:
//         Node* start;
//     };
// }