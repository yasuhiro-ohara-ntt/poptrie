
#include "poptrie_fib.h"

/*
 * Insert an entry to the FIB mapping table
 */
int
poptrie_fib_ref(struct poptrie_fib *poptrie_fib, void *nexthop)
{
    int i;
    int n;

    /* Find the FIB entry mapping first */
    for ( i = 0; i < poptrie_fib->sz; i++ ) {
        if ( poptrie_fib->entries[i].entry == nexthop ) {
            /* Found the matched entry */
            poptrie_fib->entries[i].refs++;
            n = i;
            break;
        }
    }
    if ( i == poptrie_fib->sz ) {
        /* No matching FIB entry was found, then find an available slot */
        for ( i = 0; i < poptrie_fib->sz; i++ ) {
            if ( poptrie_fib->entries[i].refs <= 0 ) {
                /* Found */
                n = i;
                break;
            }
        }
        if ( i == poptrie_fib->sz ) {
            /* The FIB mapping table is full */
            return -1;
        }

        /* Append new FIB entry */
        poptrie_fib->entries[n].entry = nexthop;
        poptrie_fib->entries[n].refs = 1;
    }

    return n;
}

/*
 * Dereference an entry from the FIB mapping table
 */
void
poptrie_fib_deref(struct poptrie_fib *poptrie_fib, void *nexthop)
{
    int i;

    for ( i = 0; i < poptrie_fib->sz; i++ ) {
        if ( poptrie_fib->entries[i].entry == nexthop ) {
            /* Found the matched entry */
            poptrie_fib->entries[i].refs--;
            break;
        }
    }
}


