#include "SplayTree.cpp"

int main ()
{
    SplayTree<int> Tree1;
    Tree1.insert(5,2);
    Tree1.insert(8,4);
    Tree1.insert(10,5);
    //Tree1.remove(5);
    Tree1.remove(0);
    Tree1.search(5);
    Tree1.print(std::cout, Tree1.root_);
    std::cout << "nu ono nakonez-to sobralos" << std::endl;
    std::cout << *Tree1.max();
    std::cout << std::endl;
    std::cout << *Tree1.min();


    return 0;
}
