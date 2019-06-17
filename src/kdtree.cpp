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

double KDNode::coord(const size_t& idx) { return x.at(idx); }

KDNode::operator bool() { return !x.empty(); }
KDNode::operator point_t() { return x; }
KDNode::operator size_t() { return index; }
KDNode::operator point_index() { return point_index(x, index); }

KDNode_ptr NewKDNode_ptr() {
    KDNode_ptr my_node = std::make_shared<KDNode>();

    return my_node;
}

inline double dist2(const point_t& a, const point_t& b) {
    double distc {0};
    for (size_t i=0; i<a.size(); ++i) {
        double di = a.at(i) - b.at(i);
        distc += di * di;
    }

    return distc;
}
