// #include <string>
// #include <vector>
// #include "Node.hpp"
// #include "OrgChart.hpp"
// #include "iterator.hpp"

// using namespace std;

// namespace ariel{

//     iterator::iterator(OrgChart* org){
//         auto it = org->getRoot();
//     }
//     iterator::~iterator(){
        
//     }
//     iterator iterator::begin_level_order(){
//         return this->iterator();
//     }
//     iterator iterator::end_level_order(){
//         return iterator(OrgChart *org);
//     }
//     iterator iterator::begin_reverse_order(){
//         return iterator();
//     }
//     iterator iterator::end_reverse_order(){
//         return iterator();
//     }
//     iterator iterator::begin_preorder(){
//         return iterator();
//     }
//     iterator iterator::end_preorder(){
//         return iterator();
//     }
//     iterator iterator::operator++(){
//         Node *tmp = start;
//         ++(*this);
//         return iterator();
//     }
//     iterator iterator::operator--(){
//         return iterator();
//     }
//     iterator iterator::operator--(int){
//         return iterator();
//     }
//     Node* iterator::operator*(){
//         return nullptr;
//     }
//     bool iterator::operator==(const iterator& other){
//         return this->start == other.start;
//     }
//     bool iterator::operator!=(const iterator& other){
//         return !(*this == other);
//     }
//     int iterator::size(){
//         return 0;
//     }

// }