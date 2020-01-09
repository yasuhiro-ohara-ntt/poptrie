
#ifndef _POPTRIE_RIB_
#define _POPTRIE_RIB_

/* Leaf node; 16-bit value */
typedef u16 poptrie_leaf_t;

/*
 * Radix tree node
 */
struct radix_node {
    int valid;
    struct radix_node *left;
    struct radix_node *right;

    /* Next hop */
    int len;
    poptrie_leaf_t nexthop;

    /* Propagated route for invalid intermediate nodes from a valid parent */
    struct radix_node *ext;

    /* Mark for update */
    int mark;
};

#endif /*_POPTRIE_RIB_*/

