/**
 * @file queue.c
 * @brief Implementation of a queue that supports FIFO and LIFO operations.
 *
 * This queue implementation uses a singly-linked list to represent the
 * queue elements. Each queue element stores a string value.
 *
 * Assignment for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 * Extended to store strings, 2018
 *
 * TODO: fill in your name and Andrew ID
 * @author Carolt <wzyb-52@sjtu.edu.cn>
 */

#include "queue.h"
#include "harness.h"

#include <stdlib.h>
#include <string.h>

/**
 * @brief Allocates a new queue
 * @return The new queue, or NULL if memory allocation failed
 */
queue_t *queue_new(void) {
    queue_t *q = malloc(sizeof(queue_t));
    /* What if malloc returned NULL? */
    if (!q) return NULL;
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

/**
 * @brief Frees all memory used by a queue
 * @param[in] q The queue to free
 */
void queue_free(queue_t *q) {
    /* How about freeing the list elements and the strings? */
    /* Free queue structure */
    if (!q || !q->head) return;
    for (list_ele_t* ptr = q->head; ptr != NULL; ptr = q->head) {
        q->head = ptr->next;
        free(ptr->value);
        free(ptr);
    }
    free(q);
}

/**
 * @brief Attempts to insert an element at head of a queue
 *
 * This function explicitly allocates space to create a copy of `s`.
 * The inserted element points to a copy of `s`, instead of `s` itself.
 *
 * @param[in] q The queue to insert into
 * @param[in] s String to be copied and inserted into the queue
 *
 * @return true if insertion was successful
 * @return false if q is NULL, or memory allocation failed
 */
bool queue_insert_head(queue_t *q, const char *s) {
    list_ele_t *newh;
    /* What should you do if the q is NULL? */
    if (!q) q = queue_new();
    newh = malloc(sizeof(list_ele_t));
    /* Don't forget to allocate space for the string and copy it */
    char *newvalue = (char*)malloc(strlen(s) + 1);
    /* What if either call to malloc returns NULL? */
    if (!newh || !newvalue) return false;
    strcpy(newvalue, s);
    newh->value = newvalue;
    newh->next = q->head;
    q->head = newh;
    /* Update the size. */
    q->size += 1;
    /* Special case: q originly is null. */
    if (!q->head->next) q->tail = q->head;
    return true;
}

/**
 * @brief Attempts to insert an element at tail of a queue
 *
 * This function explicitly allocates space to create a copy of `s`.
 * The inserted element points to a copy of `s`, instead of `s` itself.
 *
 * @param[in] q The queue to insert into
 * @param[in] s String to be copied and inserted into the queue
 *
 * @return true if insertion was successful
 * @return false if q is NULL, or memory allocation failed
 */
bool queue_insert_tail(queue_t *q, const char *s) {
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    if (!q) {
        return queue_insert_head(q, s);
    }
    list_ele_t *newh = malloc(sizeof(list_ele_t));
    char   *newvalue = (char*)malloc(strlen(s) + 1);
    /* What if either call to malloc returns NULL? */
    if (!newh || !newvalue) return false;
    strcpy(newvalue, s);
    newh->next = NULL;
    newh->value = newvalue;
    q->tail->next = newh; 
    q->tail = newh;
    /* Update the size. */
    q->size += 1;
    return false;
}

/**
 * @brief Attempts to remove an element from head of a queue
 *
 * If removal succeeds, this function frees all memory used by the
 * removed list element and its string value before returning.
 *
 * If removal succeeds and `buf` is non-NULL, this function copies up to
 * `bufsize - 1` characters from the removed string into `buf`, and writes
 * a null terminator '\0' after the copied string.
 *
 * @param[in]  q       The queue to remove from
 * @param[out] buf     Output buffer to write a string value into
 * @param[in]  bufsize Size of the buffer `buf` points to
 *
 * @return true if removal succeeded
 * @return false if q is NULL or empty
 */
bool queue_remove_head(queue_t *q, char *buf, size_t bufsize) {
    /* You need to fix up this code. */
    if (!q) return false;
    /* Then the removal will succeed. */
    list_ele_t *ptr = q->head;
    q->head = q->head->next;
    /* Copy value to buf. */
    size_t vallen = strlen(ptr->value);
    size_t length = bufsize - 1 > vallen ? vallen : bufsize - 1;
    strncpy(buf, ptr->value, length);
    buf[length] = '\0';
    /* Update the size. */
    q->size -= 1;
    /* Release the memory of head element. */
    free(ptr->value);
    free(ptr);
    /* Special case: the origin queue has only one element. */
    if (!q->head) q->tail = NULL;
    return true;
}

/**
 * @brief Returns the number of elements in a queue
 *
 * This function runs in O(1) time.
 *
 * @param[in] q The queue to examine
 *
 * @return the number of elements in the queue, or
 *         0 if q is NULL or empty
 */
size_t queue_size(queue_t *q) {
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    return q->size;
}

/**
 * @brief Reverse the elements in a queue
 *
 * This function does not allocate or free any list elements, i.e. it does
 * not call malloc or free, including inside helper functions. Instead, it
 * rearranges the existing elements of the queue.
 *
 * @param[in] q The queue to reverse
 */
void queue_reverse(queue_t *q) {
    /* You need to write the code for this function */
    if (!q || q->size < 2) return;
    list_ele_t *ptr, *head = q->head, *tail = q->tail;
    size_t cnt = q->size;
    for (size_t i = 1; i < cnt; ++i) {
        ptr = head->next;
        head->next = tail->next;
        tail->next = head;
        head = ptr; 
    }
    ptr = q->head;
    q->head = q->tail;
    q->tail = ptr;
}
