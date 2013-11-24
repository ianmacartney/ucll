#include <stdio.h>
 
#define TEST_SIZE 15
int main(int argc, void **argv) {
    static struct ll na[TEST_SIZE];
    static struct ll *list;
    int i;
 
    ll_init_list(&list);
    for (i = 0; i < TEST_SIZE; i++) {
        ll_init_node(&na[i]);
        ll_push(&list, &na[i]);
    }
    assert(ll_head(&list));
    assert(i == TEST_SIZE);
    struct ll *n;
    for (n = ll_head(&list); n; n = ll_next(&list, n)) {
        i--;
        assert(n == &na[i]);
    }
    printf("Countdown from %i to 0!\r\n", TEST_SIZE - 1);
    while(ll_head(&list) && (n = ll_pop(&list))) {
        printf("%5li!\r\n", n - na);
    }
    assert(ll_head(&list) == NULL);
    assert(i == 0);
    for (; i < TEST_SIZE; i++) {
        ll_append(&list, &na[i]);
    }
    printf("Count 0 up to %i!\r\n", TEST_SIZE - 1);
    struct ll *head = ll_head(&list);
    for (i = 0; i < TEST_SIZE; i++) {
        n = ll_pop_append(&list);
        printf("%5li!\r\n", n - na);
        assert(n == &na[i]);
    }
    assert(head == ll_head(&list));
    static struct ll extra1, extra2;
    static struct ll *extralist;
    ll_init_list(&extralist);
    ll_init_node(&extra1);
    ll_push(&extralist, &extra1);
    ll_init_node(&extra2);
    ll_append(&extralist, &extra2);
    ll_append(&extralist, list);//that's right! It works for lists too!
    assert(ll_pop(&extralist) == &extra1);
    assert(ll_pop(&extralist) == &extra2);
    assert(ll_pop(&extralist) == &na[0]);
}
