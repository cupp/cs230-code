#include "vector.h"
#include <stdlib.h>
#include <assert.h>

/* Private interface */

static const int StartSize = 1;      /* initial vector capacity */
static const float GrowthRate = 1.8; /* geometric growth of vector capacity */

static int *data = NULL;    /* pointer to vector elements */
static int vectorsize = 0;  /* current size of vector */
static int capacity = 0;    /* current reserved memory for vector */

/* Function definitions */

int push_back(int item)
/* Add element to back of vector. Return index of new element if successful,
 * and -1 if fails. */
{
    /* If out-of-space, allocate more. */
    if (vectorsize == capacity) { 
        int newsize = (capacity == 0) ? StartSize : (int)(capacity*GrowthRate + 1.0); 
        int *p = (int *)realloc(data, newsize*sizeof(int));
        if (p == NULL)
            return -1;

        capacity = newsize; /* allocate succeeds, update data-structure */
        data = p;
    }

    /* We have enough room. */
    data[vectorsize] = item;
    return vectorsize++;
}

int pop_back(void)
/* Return element from back of vector, and remove it from the vector. */
{
    assert(vectorsize > 0);
    return data[--vectorsize];
}

int* get_element(int index)
/* Return pointer to the element at the specified index. */
{
    assert(index >= 0 && index < vectorsize);
    return data + index;
}

/* Manual size operations. */
int  get_size(void) { return vectorsize; }
int  get_capacity(void) { return capacity; }

int set_size(int size)
/* Set vector size. Return 0 if successful, -1 if fails. */
{
    if (size > capacity) {
        int *p = (int *)realloc(data, size*sizeof(int));
        if (p == NULL)
            return -1;

        capacity = size; /* allocate succeeds, update data-structure */
        data = p;
    }

    vectorsize = size;
    return 0;
}

int set_capacity(int size)
/* Shrink or grow allocated memory reserve for array.
 * A size of 0 deletes the array. Return 0 if successful, -1 if fails. */
{
    if (size != capacity) {
        int *p = (int *)realloc(data, size*sizeof(int));
        if (p == NULL && size > 0)
            return -1;

        capacity = size;
        data = p;
    }

    if (size < vectorsize)
        vectorsize = size;
    return 0;
}
