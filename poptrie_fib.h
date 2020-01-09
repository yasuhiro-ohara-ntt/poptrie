
#ifndef _POPTRIE_FIB_
#define _POPTRIE_FIB_

/*
 * FIB mapping table
 */
struct poptrie_fib_entry {
    void *entry;
    int refs;
};
struct poptrie_fib {
    struct poptrie_fib_entry *entries;
    int sz;
};

int poptrie_fib_ref(struct poptrie_fib *poptrie_fib, void *nexthop);
void poptrie_fib_deref(struct poptrie_fib *poptrie_fib, void *nexthop);

#endif /*_POPTRIE_FIB_*/

