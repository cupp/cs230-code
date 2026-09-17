/* Expandable vector, grows in-place as new elements are added to the back. */

#ifndef EXPANDABLE_VECTOR_H_
#define EXPANDABLE_VECTOR_H_

/* Vector access operations. */
int push_back(int item);
int pop_back(void);
int* get_element(int index);

/* Manual resizing operations. */
int get_size(void);
int set_size(int size);
int get_capacity(void);
int set_capacity(int size);

#endif
