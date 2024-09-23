#ifndef WQSORT_H_INCLUDED
#define WQSORT_H_INCLUDED

void swapObjects(void* a, void* b, size_t size);
void wqsort(void* ptr, size_t count, size_t size, int (*comp)(const void*, const void*));

#endif