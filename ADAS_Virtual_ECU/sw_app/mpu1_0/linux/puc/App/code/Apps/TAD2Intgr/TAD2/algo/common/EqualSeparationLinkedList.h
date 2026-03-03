// ----------------------------------------------------------------------------
// --- Written by Joshua Teichroeb [06-Jun-2019]
// --- Last Modified by Joshua Teichroeb [06-Jun-2019]
// --- Copyright (c) Magna Vectrics (MEVC) 2017
// ----------------------------------------------------------------------------

#ifndef __EQUAL_SEPARATION_LINKED_LIST__H_
#define __EQUAL_SEPARATION_LINKED_LIST__H_

#ifdef __QNX__
    #include "mecl/mecl.h"
#else
    #include "MECL/mecl.h"
#endif

/*
* Interface for EqualSeparationLinkedList node.
*/
namespace LL
{
    struct LinkedListNode
    {
        struct LinkedListNode* next;
        struct LinkedListNode* prev;
    };

    /*
    * Linked list where continuously inserting elements which differ by some distance results
    * in a list whose elements all have approximately the same distance between them, so long
    * as when 'insert()' returns true, that distance is doubled. (Used in 'AngleSampling.h')
    *
    * Must have odd size.
    */
    template <class element_type, uint32_t c_size>
    class EqualSeparationLinkedList
    {
    public:
        EqualSeparationLinkedList();

        bool_t insert( element_type e );
        void clear();
        element_type* head();
        element_type* next_node() const;
        bool_t is_full() const;
        inline element_type* getM_NextNode() const
        {
            return m_nextNode;
        }

    private:
        element_type m_buf[c_size];
        element_type* m_prevNode;
        element_type* m_nextNode;
        uint32_t m_curCount;
        bool_t m_isFull;

    };
}

#endif  // !__EQUAL_SEPARATION_LINKED_LIST__H_
