#include "../include/SplayTree.hpp"

template <typename T>
SplayTree<T>::Node::Node(T value_) : value(value_), left_(nullptr), right_(nullptr), parent_(nullptr) {};

template <typename T>
SplayTree<T>::Node::~Node() {
    left_ = nullptr;
    right_ = nullptr;
};

template <typename T>
auto SplayTree<T>::Node::equal(std::shared_ptr<Node> tree) const noexcept -> bool
{
    if ((left_ && !tree->left_) || (right_ && !tree->right_))
        return false;
    if ((!left_ && tree->left_) || (!right_ && tree->right_))
        return false;

    bool equalLeft = true; bool equalRight = true;
    if (value != tree->value)
        return false;
    else
    {
        if (!left_ && !right_)
            return true;
        if (left_)
            equalLeft = left_->equal(tree->left_);
        if (right_)
            equalRight = right_->equal(tree->right_);
        return equalLeft && equalRight;
    }
}

template <typename T>
SplayTree<T>::SplayTree() : root_(nullptr) {};

template <typename T>
SplayTree<T>::SplayTree(const std::initializer_list<T>& list) : root_(nullptr)
{
    for (auto it = list.begin(); it != list.end(); ++it)
        insert(*it);
};

template <typename T>
auto SplayTree<T>::rotate_left(std::shared_ptr<Node> node) -> void {
    std::shared_ptr<Node> tmp = node->left_;
    if (node->parent_ == nullptr)
        root_ = tmp;
    else if (node == node->parent_->left_)
        node->parent_->left_ = tmp;
    else
        node->parent_->right_ = tmp;
    tmp->parent_ = node->parent_;
    node->left_ = tmp->right_;
    if (node->left_ != nullptr)
        node->left_->parent_ = node;
    tmp->right_ = node;
    node->parent_ = tmp;
}

template <typename T>
auto SplayTree<T>::rotate_right(std::shared_ptr<Node> node) -> void {
    std::shared_ptr<Node> tmp = node->right_;
    if (node->parent_ == nullptr)
        root_ = tmp;
    else if (node == node->parent_->left_)
        node->parent_->left_ = tmp;
    else
        node->parent_->right_ = tmp;
    tmp->parent_ = node->parent_;
    node->right_ = tmp->left_;
    if (node->right_ != nullptr)
        node->right_->parent_ = node;
    tmp->left_ = node;
    node->parent_ = tmp;
}

template <typename T>
auto SplayTree<T>::splay(std::shared_ptr<Node> node) -> void {
    if (node == nullptr)
        return;
    while (node->parent_ != nullptr && node->parent_->parent_ != nullptr) {
        if (node == node->parent_->left_) {
            if (node->parent_ == node->parent_->parent_->left_) {
                // ZigZig
                rotate_left(node->parent_->parent_);
                rotate_left(node->parent_);
            }
            else {
                // ZigZag
                rotate_left(node->parent_);
                rotate_right(node->parent_);
            }
        }
        else {
            if (node->parent_ == node->parent_->parent_->right_) {
                // ZigZig
                rotate_right(node->parent_->parent_);
                rotate_right(node->parent_);
            }
            else {
                // ZigZag
                rotate_right(node->parent_);
                rotate_left(node->parent_);
            }
        }
    }
    if (node->parent_ == nullptr) {
        return;
    }
    if (node == node->parent_->left_) {
        // Zig
        rotate_left(node->parent_);
    }
    else {
        // Zig
        rotate_right(node->parent_);
    }
}

template <typename T>
auto SplayTree<T>::insert(const T& value) -> bool
{
    bool foundPlace = false;
    if (root_ == nullptr) {
        root_ = std::make_shared<Node>(value);
        return true;
    }

    std::shared_ptr<Node> thisNode = root_;
    while (!foundPlace)
    {
        if (value == thisNode->value)
            return false;
        if (value < thisNode->value)
        {
            if (!thisNode->left_)
            {
                thisNode->left_ = std::make_shared<Node>(value);
                thisNode->left_->parent_ = thisNode;
                thisNode = thisNode->left_;
                foundPlace = true;
            }
            else
                thisNode = thisNode->left_;
        }
        else if (!thisNode->right_)
        {
            thisNode->right_ = std::make_shared<Node>(value);
            thisNode->right_->parent_ = thisNode;
            thisNode = thisNode -> right_;
            foundPlace = true;
        }
        else
            thisNode = thisNode->right_;
    }
    splay(thisNode);
    this -> root_ = thisNode;
    return foundPlace;
};


template <typename T>
auto SplayTree<T>::search(const T& value) -> const T*
{
    if (!root_)
        return nullptr;

    std::shared_ptr<Node> thisNode = root_;
    while (1)
    {
        if (value == thisNode->value)
        {
            splay(thisNode);
            this -> root_ = thisNode;
            return &thisNode->value;
        }
        else if (value < thisNode->value)
            if (thisNode->left_)
                thisNode = thisNode->left_;
            else
            {
                splay(thisNode);
                this -> root_ = thisNode;
                return nullptr;
            }
        else {
            if (thisNode->right_)
                thisNode = thisNode->right_;
            else
            {
                splay(thisNode);
                this -> root_ = thisNode;
                return nullptr;
            }
        }
    }
};

template <typename T>
auto SplayTree<T>::max(std::shared_ptr<Node> left_tree) const -> std::shared_ptr<Node> {
    if (left_tree == nullptr)
        return nullptr;
    std::shared_ptr<Node> tmp = left_tree;
    while (tmp->right_ != nullptr)
        tmp = tmp->right_;
    return tmp;
}

template <typename T>
auto SplayTree<T>::merge(std::shared_ptr<Node> left_tree, std::shared_ptr<Node> right_tree) -> bool {
    std::shared_ptr<Node> new_root = max(left_tree);
    if (new_root == nullptr)
        return false;
    splay(new_root);

    new_root->right_ = right_tree;
    if (right_tree != nullptr)
        right_tree->parent_ = new_root;
    return true;
}

template <typename T>
auto SplayTree<T>::remove(const T& value) -> bool {
    if(search(value))
    {
        search(value);
        if (root_->right_ == nullptr) {
            root_ = root_->left_;
            if (root_ != nullptr)
                root_->parent_ = nullptr;
            return true;
        }

        if (!merge(root_->left_, root_->right_)) {
            root_ = root_->right_;
            if (root_ != nullptr)
                root_->parent_ = nullptr;
            return true;
        }
        return true;
    }
    else return false;
}

template <typename T>
auto SplayTree<T>::min(std::shared_ptr<Node> tree) const -> std::shared_ptr<Node>
{
    if (tree == nullptr)
        return nullptr;
    std::shared_ptr<Node> tmp = tree;
    while (tmp->left_ != nullptr)
        tmp = tmp->left_;
    return tmp;
}

template <typename T>
auto SplayTree<T>::operator == (const SplayTree& tree) -> bool
{
    return (root_->equal(tree.root_));
};
