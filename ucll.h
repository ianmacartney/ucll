#ifndef SOMETHING
#define SOMETHING
//INCLUDE

void ll_init_list(struct ll **tail);
void ll_init_node(struct ll *n);
struct ll *ll_head(struct ll **list);
//onto top of stack
void ll_push(struct ll **list, struct ll *n);
//onto end of list
void ll_append(struct ll **list, struct ll *n);
//remove and return top of stack
struct ll *ll_pop(struct ll **list);
//returns pop() result and re-appends it
struct ll *ll_pop_append(struct ll **list);
//returns element after n or NULL if at end
struct ll *ll_next(struct ll **list, struct ll *n);

#endif

