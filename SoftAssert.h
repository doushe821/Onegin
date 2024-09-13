#ifndef SOFT_ASSERT_INCLUDED
#define SOFT_ASSERT_INLCUDED

#include <stdio.h>

#ifdef NWHISPER
#define whisper
#define cwhisper
#else
#define cwhisper(condition, message) if(!condition) fprintf(stderr, "%s", message)
#define whisper(message) fprintf(stderr, "%s", message)
#endif

#endif