#ifndef SOFT_ASSERT_INCLUDED
#define SOFT_ASSERT_INLCUDED

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

//#include "vibrantPrint.h"
void scream(const char* condition_s, const char* file, const char* func, int line, \
                 const char* comment, ...);
void whisper(const char* condition_s, const char* file, const char* func, int line, \
                 const char* comment, ...);


void scream(const char* condition_s, const char* file, const char* func, int line, \
                 const char* comment, ...);




#ifdef NDEBUG
#define whisper
#else
#define whisper(condition, comment, ...) if(condition) \
{ scream(#condition, __FILE__, __func__, \
              __LINE__, comment, ##__VA_ARGS__) \
} else /
#endif

#ifdef NDEBUG
#define scream
#else
#define scream(condition, comment, ...) if(condition) \
{ scream(#condition, __FILE__, __func__, \
              __LINE__, comment, ##__VA_ARGS__) \
} else /
#endif


#endif

