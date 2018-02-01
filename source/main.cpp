#include "SplayTree.cpp"

int main ()
{
    SplayTree<int> Tree1;
    Tree1.insert(5,2);
    Tree1.insert(8,4);
    Tree1.insert(10,5);
    Tree1.insert(3,8);
    Tree1.insert(6,1234);
    Tree1.insert(48,51);
    Tree1.insert(7,14);
    Tree1.insert(9,30);
    Tree1.insert(11,534);
    //Tree1.remove(5);
    //Tree1.remove(0);
    Tree1.search(5);
    Tree1.print(std::cout, Tree1.root_, 0);
    std::cout << "nu ono nakonez-to sobralos" << std::endl;


    return 0;
}
