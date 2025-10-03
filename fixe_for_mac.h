#if defined(__GNUC__) && !defined(__clang__)
  #ifndef _Alignof
    #define _Alignof(type) __alignof__(type)
  #endif
#endif
