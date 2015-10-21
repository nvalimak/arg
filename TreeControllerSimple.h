#ifndef _TreeControllerSimple_h_
#define _TreeControllerSimple_h_
#include "default.h"
#include "Tree.h"
#include <vector>
#include <string>
#include <utility>

/**
 * Controller to handle tree updates (simple version)
 */
class TreeControllerSimple
{
public:
    TreeControllerSimple (PointerTree &t_, bool debug_, std::string dotfile_)
        : t(t_), recombine(), updatedThisStep(), step(0), debug(debug_), dotfile(dotfile_)
    { }
    void process(InputColumn const &, unsigned);
    void rewind(InputColumn const &, unsigned);

    // Debug functionality
    unsigned countGhostBranches(PointerTree::PointerNode *);
    unsigned countUnaryGhosts(PointerTree::PointerNode *);
    unsigned countBranchingGhosts(PointerTree::PointerNode *);
    unsigned countActive(PointerTree::PointerNode *);
    void deFloatAll(PointerTree::PointerNode *);
        
private:
    std::pair<int, int> reduce(PointerTree::PointerNode *, InputColumn const &);
    void resolveNonBinary(PointerTree::PointerNode *);
    std::pair<int,int> recombineStrategy(PointerTree::PointerNode *);
    void recombineSubtrees(PointerTree::PointerNode *, bool, bool);
    void recombineNonBinarySubtrees(unsigned, bool, bool);
    void findReduced(PointerTree::PointerNode *, InputLabel);

    PointerTree &t;
    std::vector<PointerTree::PointerNode *> recombine;
    std::vector<PointerTree::PointerNode *> updatedThisStep;
    unsigned step;
    bool debug;
    std::string dotfile;
    
    TreeControllerSimple();
    // No copy constructor or assignment
    TreeControllerSimple(TreeControllerSimple const&);
    TreeControllerSimple& operator = (TreeControllerSimple const&);
};
#endif