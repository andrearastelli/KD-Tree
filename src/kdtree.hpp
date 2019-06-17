#ifndef H_KDTREE
#define H_KDTREE


#include <memory>
#include <algorithm>
#include <vector>


using point_t = std::vector<double>;
using index_t = std::vector<size_t>;
using point_index = typename std::pair<point_t, size_t>;


class KDNode {
public:
    using KDNode_ptr = std::shared_ptr<KDNode>;

    std::size_t index;
    point_t x;
    KDNode_ptr left;
    KDNode_ptr right;

    KDNode();
    KDNode(
        const point_t&, const size_t&,
        const KDNode_ptr&, const KDNode_ptr&);
    KDNode(const point_index&, const KDNode_ptr&, const KDNode_ptr&);

    ~KDNode();

    double coord(const size_t&);

    explicit operator bool();
    explicit operator point_t();
    explicit operator size_t();
    explicit operator point_index();
};


using KDNode_ptr = std::shared_ptr<KDNode>;


inline double dist(const point_t&, const point_t&);
inline double dist(const KDNode_ptr&, const KDNode_ptr&);


class Comparer {
public:
    size_t idx;

    explicit Comparer(size_t idx);

    inline bool compare_idx(const point_index&, const point_index&);
};


using point_index_array = typename std::vector<point_index>;


inline void sort_on_idx(
    const point_index_array::iterator&,
    const point_index_array::iterator&,
    size_t idx);


using point_vector = std::vector<point_t>;


class KDTree {
private:
    KDNode_ptr root;
    KDNode_ptr leaf;

    KDNode_ptr make_tree(
        const point_index_array::iterator& begin,
        const point_index_array::iterator& end,
        const size_t& length,
        const size_t& level);

public:
    KDTree() = default;
    explicit KDTree(point_vector point_array);

private:
    KDNode_ptr nearest_(
        const KDNode_ptr& branch,
        const point_t& pt,
        const size_t& level,
        const KDNode_ptr& best,
        const double& best_dist);

    KDNode_ptr nearest_(const point_t& pt);

public:
    point_t nearest_point(const point_t& pt);
    size_t nearest_index(const point_t& pt);
    point_index nearest_point_index(const point_t& pt);

private:
    point_index_array neighborood_(
        const KDNode_ptr& branch,
        const point_t& pt,
        const double& rad,
        const size_t& level);

public:
    point_index_array neighborood(const point_t& pt, const double& rad);
    point_vector neighborood_points(const point_t& pt, const double& rad);
    index_t neighborood_indices(const point_t& pt, const double& rad);
};


#endif
