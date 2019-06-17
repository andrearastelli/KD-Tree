#include "kdtree.hpp"

#include <cmath>
#include <functional>
#include <iterator>
#include <limits>


KDNode::KDNode() = default;

KDNode::KDNode(
    const point_t& pt, const size_t& idx_,
    const KDNode_ptr& left_, const KDNode_ptr& right_)
    : x{pt}, index{idx_}, left{left_}, right{right_} {}

KDNode::KDNode(
    const point_index& pi,
    const KDnode_ptr& left_, const KDNode_ptr& right_)
    : x{pi.first}, index{pi.second}, left{left_}, right{right_} {}

KDNode::~KDNode() = default;
