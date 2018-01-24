#ifndef SPLAYTREE_SPLAYTREE_H
#define SPLAYTREE_SPLAYTREE_H

#include <iostream>
#include <memory>

template <typename T>
class SplayTree
{
public:
    struct Node {
        std::shared_ptr<Node> left_;
        std::shared_ptr<Node> right_;
        std::shared_ptr<Node> parent_;
        T value;

        Node(T value_);
        ~Node();

        auto equal(std::shared_ptr<Node> tree) const noexcept -> bool;
    };

    SplayTree();
    SplayTree(const std::initializer_list<T>& list);
    ////Splay///
    auto rotate_left(std::shared_ptr<Node> node) -> void;
    auto rotate_right(std::shared_ptr<Node> node) -> void;
    auto splay(std::shared_ptr<Node> node) -> void;
    ///Remove///
    auto remove(const T& value) -> bool;
    auto max(std::shared_ptr<Node> left_tree) const -> std::shared_ptr<Node>;
    auto merge(std::shared_ptr<Node> left_tree, std::shared_ptr<Node> right_tree) -> bool;
    ///Insert///
    auto insert(const T& value) -> bool;
    ///Search///
    auto search(const T& value) -> const T*;
    ///Min///
    auto min(std::shared_ptr<Node> tree) const -> std::shared_ptr<Node>;

    auto operator == (const SplayTree& tree) -> bool;

private:
    std::shared_ptr<Node> root_;
};
#endif //SPLAYTREE_SPLAYTREE_H