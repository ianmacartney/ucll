#include <stddef.h>
#include <assert.h>
//INCLUDE
 
void ll_init_list(struct ll **tailp) {
    *tailp = NULL;
}

void ll_init_node(struct ll *n) {
    n->next = n;
}

#define LL_ASSERT_VALID(n) assert({ assert(n); struct ll *cur = n->next; \
        while (cur != n) { assert(cur); cur = cur->next; } 1; })
 
struct ll *ll_head(struct ll **tail) {
    assert(tail);
    return *tail? (*tail)->next: NULL;
}
 
void ll_push(struct ll **tail, struct ll *n) {
    assert(tail);
    LL_ASSERT_VALID(n);
    if (*tail) {
        struct ll *head = (*tail)->next;
        (*tail)->next = n->next? n->next: n;
        n->next = head;
    } else {
        n->next = n;
        *tail = n;
    }
}
 
void ll_append(struct ll **tail, struct ll *n) {
    ll_push(tail, n);
    *tail = n;
}
 
struct ll *ll_pop(struct ll **tail) {
    assert(tail);
    struct ll *head = (*tail)->next;
    if (head == *tail) {
        *tail = NULL;
    } else {
        (*tail)->next = head->next;
    }
    head->next = head;
    return head;
}
 
struct ll *ll_pop_append(struct ll **tail) {
    assert(tail);
    if (*tail) {
        *tail = (*tail)->next;
    }
    return *tail;
}
 
struct ll *ll_next(struct ll **tail, struct ll *n) {
    assert(tail);
    return n == *tail? NULL: n->next;
}
 
