#ifndef LIST_H
#define LIST_H

/* 单链表和节点的定义 */

typedef struct slist_node_t
{
    struct slist_node_t *next;
} slist_node_t;

typedef struct
{
    slist_node_t *head;
    slist_node_t *tail;
} slist_t;

/* 双链表和节点的定义 */

typedef struct dlist_node_t
{
    struct dlist_node_t *next;
    struct dlist_node_t *prev;
} dlist_node_t;

typedef struct
{
    struct dlist_node_t *head;
    struct dlist_node_t *tail;
} dlist_t;

/* 双链表初始化 */

#define DLIST_INIT(list) \
do { \
    ((dlist_t *)(list))->head = NULL; \
    ((dlist_t *)(list))->tail = NULL; \
} while(0)

#define DLIST_FIRST(list)   (((dlist_t *)(list))->head)         /* 取双链表第一节点 */
#define DLIST_LAST(list)    (((dlist_t *)(list))->tail)         /* 取双链表最后节点 */
#define DLIST_NEXT(node)    (((dlist_node_t *)(node))->next)    /* 取双链表下一个节点 */
#define DLIST_PREV(node)    (((dlist_node_t *)(node))->prev)    /* 取双链表上一个节点 */
#define DLIST_EMPTY(list)   (((dlist_t *)list)->head == NULL)   /* 双链表是否为空 */

/* 在双链表指定节点的后面添加新节点 */

#define DLIST_INSERT(list,prev_node,node) \
    do { \
        dlist_node_t *temp; \
        if ((prev_node) == NULL) \
        { \
            temp = ((dlist_t *)(list))->head; \
            ((dlist_t *)(list))->head = (dlist_node_t *)(node); \
        } \
        else \
        { \
            temp = ((dlist_node_t *)(prev_node))->next; \
            ((dlist_node_t *)(prev_node))->next = (dlist_node_t *)(node); \
        } \
        if (temp == NULL) \
        { \
            ((dlist_t *)(list))->tail = (dlist_node_t *)(node); \
        } \
        else \
        { \
           temp->prev = (dlist_node_t *)(node); \
        } \
        ((dlist_node_t *)(node))->next = temp; \
        ((dlist_node_t *)(node))->prev = (dlist_node_t *)(prev_node); \
    }while(0)

/* 在双链表的最后添加新节点 */

#define DLIST_ADD(list,node) \
    do { \
        dlist_node_t *list_tail = (list)->tail; \
        DLIST_INSERT ((list), list_tail, (node)); \
    } while(0)

/* 删除双链表中指定的节点 */

#define DLIST_REMOVE(list,node) \
    do { \
        if (((dlist_node_t *)(node))->prev == NULL) \
        { \
            ((dlist_t *)(list))->head = ((dlist_node_t *)(node))->next; \
        } \
        else \
        { \
            ((dlist_node_t *)(node))->prev->next = ((dlist_node_t *)(node))->next; \
        } \
        if (((dlist_node_t *)(node))->next == NULL) \
        { \
            ((dlist_t *)(list))->tail = ((dlist_node_t *)(node))->prev; \
        } \
        else \
        { \
            ((dlist_node_t *)(node))->next->prev = ((dlist_node_t *)(node))->prev; \
        } \
    } while(0)

/* 从双链表中取出最前节点 */

#define DLIST_GET(list,node) \
    do { \
        (node) = (void *)((dlist_t *)(list))->head; \
        if ((node) != NULL) \
        { \
            ((dlist_t *)(list))->head = ((dlist_node_t *)(node))->next; \
            if (((dlist_node_t *)(node))->next == NULL) \
            { \
                ((dlist_t *)(list))->tail = NULL; \
            } \
            else \
            { \
                ((dlist_node_t *)(node))->next->prev = NULL; \
            } \
        } \
    } while(0)

/* 单链表初始化 */

#define SLIST_INIT(list) \
    do { \
        ((slist_t *)(list))->head = NULL; \
        ((slist_t *)(list))->tail = NULL; \
    } while(0)

/* 在单链表的最前端添加新节点 */

#define SLIST_PUT_AT_HEAD(list,node) \
    do { \
        if ((((slist_node_t *)(node))->next = ((slist_t *)(list))->head) == NULL) \
        { \
            ((slist_t *)(list))->head = ((slist_node_t *)(node)); \
            ((slist_t *)(list))->tail = ((slist_node_t *)(node)); \
        } \
        else \
        { \
            ((slist_t *)(list))->head = (node); \
        } \
    } while(0)

/* 在单链表的最后端添加新节点 */

#define SLIST_PUT_AT_TAIL(list,node) \
    do { \
        ((slist_node_t *)(node))->next = NULL; \
        if (((slist_t *)(list))->head == NULL) \
        { \
            ((slist_t *)(list))->head = (slist_node_t *)(node); \
            ((slist_t *)(list))->tail = (slist_node_t *)(node); \
        } \
        else \
        { \
            ((slist_t *)(list))->tail->next = (slist_node_t *)(node); \
        } \
        ((slist_t *)(list))->tail = (slist_node_t *)(node); \
    } while(0)

/* 从单链表中取出最前节点 */

#define SLIST_GET(list,node) \
    do { \
        if (((node) = (void *)((slist_t *)(list))->head) != NULL) \
        { \
            ((slist_t *)(list))->head = ((slist_node_t *)(node))->next; \
        } \
    } while(0)

/* 从单链表中删除指定节点 */

#define SLIST_REMOVE(list,del_node,prev_node) \
    do { \
        if (((slist_node_t *)(prev_node)) == NULL) \
        { \
            ((slist_t *)(list))->head = ((slist_node_t *)(del_node))->next; \
            if (((slist_t *)(list))->tail == ((slist_node_t *)(del_node))) \
            { \
                ((slist_t *)(list))->tail = NULL; \
            } \
        } \
        else \
        { \
            ((slist_node_t *)(prev_node))->next = ((slist_node_t *)(del_node))->next; \
            if (((slist_t *)(list))->tail == ((slist_node_t *)(del_node))) \
            { \
                ((slist_t *)(list))->tail = ((slist_node_t *)(prev_node)); \
            } \
        } \
    } while(0)

/* 从单链表中取出指定节点的上一个节点 */

#define SLIST_PREV(list,node,prev_node) \
    do { \
        slist_node_t *temp; \
        (prev_node) = NULL; \
        temp = ((slist_t *)(list))->head; \
        if ((temp != NULL) && (temp != (node))) \
        { \
            while (temp->next != NULL) \
            { \
                if (temp->next == (node)) \
                { \
                    (prev_node) = temp; \
                    break; \
                } \
                temp = temp->next; \
            } \
        } \
    } while(0)

#define SLIST_FIRST(list)   (((slist_t *)list)->head)           /* 取单链表第一节点 */
#define SLIST_LAST(list)    (((slist_t *)list)->tail)           /* 取单链表最后节点 */
#define SLIST_NEXT(node)    (((slist_node_t *)node)->next)      /* 取单链表指定节点的下一个节点 */
#define SLIST_EMPTY(list)   (((slist_t *)list)->head == NULL)   /* 单链表是否为空 */

#endif /* LIST_H */
