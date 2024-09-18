#ifndef WQSORT_H_INCLUDED
#define WQSORT_H_INCLUDED

void wqsort(void* ptr, size_t count, size_t size, int (*comp)(const void*, const void*));

#endif