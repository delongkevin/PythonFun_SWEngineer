/*******************************************************************************
 * list.h
 *
 * Double-linked lists support
 *
 * Copyright (c) 2014-2016 Cogent Embedded Inc. ALL RIGHTS RESERVED.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *******************************************************************************/

#ifndef __PBB_LIST_H
#define __PBB_LIST_H

/*******************************************************************************
 * Types definitions
 ******************************************************************************/

/**> Forward declarations */
typedef struct __list   __list_t;
typedef struct __slist   __slist_t;

/**> Single-linked list */
struct __slist
{
    struct __slist     *next;
};
    
/* ...double-linked list */
struct __list
{
    struct __list  *next, *prev;
};

/*******************************************************************************
 * Public API
 ******************************************************************************/

static inline void __list_init(__list_t *head)
{
    head->next = head->prev = head;
}

static inline int __list_is_empty(__list_t *head)
{
    return (head->next == head);
}

static inline void __list_push_tail(__list_t *head, __list_t *item)
{
    head->prev->next = item, item->prev = head->prev;
    item->next = head, head->prev = item;
}

static inline void __list_push_head(__list_t *head, __list_t *item)
{
    head->next->prev = item, item->next = head->next;
    item->prev = head, head->next = item;
}

static inline void __list_delete(__list_t *item)
{
    item->prev->next = item->next, item->next->prev = item->prev;
    item->prev = item->next = NULL;
}

static inline __list_t * __list_pop_head(__list_t *head)
{
    __list_t   *item = head->next;

    if (item != head)
    {
        __list_delete(item);
        return item;
    }
    else
    {
        return NULL;
    }
}

static inline __list_t * __list_pop_tail(__list_t *head)
{
    __list_t   *item = head->prev;

    if (item != head)
    {
        __list_delete(item);
        return item;
    }
    else
    {
        return NULL;
    }
}

static inline __list_t * list_null(__list_t *head)
{
    return head;
}

static inline __list_t * list_first(__list_t *head)
{
    return head->next;
}

static inline __list_t * list_last(__list_t *head)
{
    return head->prev;
}

static inline __list_t * list_next(__list_t *head, __list_t *item)
{
    return item->next;
}

static inline __list_t * list_prev(__list_t *head, __list_t *item)
{
    return item->prev;
}

/*******************************************************************************
 * Single-linked list handling API
 ******************************************************************************/

static inline void __slist_init(__slist_t **head)
{
    *head = NULL;
}

static inline int __slist_is_empty(__slist_t *head)
{
    return (head == NULL);
}

static inline void __slist_push(__slist_t **head, __slist_t *item)
{
    item->next = *head;
    *head = item;
}

static inline __slist_t * __slist_pop(__slist_t **head)
{
    __slist_t  *item = *head;

    (item != NULL ? *head = item->next : 0);
    return item;
}

static inline __slist_t * slist_null(__slist_t *head)
{
    return NULL;
}

static inline __slist_t * slist_first(__slist_t *head)
{
    return head;
}

static inline __slist_t * slist_next(__slist_t *head, __slist_t *item)
{
    return item->next;
}

#endif  /* __PBB_LIST_H */
