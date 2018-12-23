#pragma once
// #define CERR false && cerr
#ifndef __OPTIMIZE__
    #define CERR cerr
#else
    #define CERR false && cerr
#endif

#define ASSERT(x)       do { if (!(x)) { CERR <<"ASSERT! " #x " Failed! line:" << __LINE__ << endl; _assert_failed(); }  } while(0)

#define EXPECT(x, y)    do { if (!((x) == (y))) { CERR <<"ASSERT! " #x " == " #y " Failed! expect:" << (y) <<" got: " << (x) << " line:" << __LINE__ << endl; _assert_failed(); }  } while(0)

inline unsigned long rdtsc(void)
{
	unsigned int hi, lo;

	__asm volatile
	    ("rdtsc" : "=a" (lo), "=d" (hi));

	return ((unsigned long)hi << 32) | lo;
}

void _assert_failed()
{
    static int errors = 0;
    ++errors;
}

#define likely( x )     __builtin_expect( (x), 1 )
#define unlikely( x )   __builtin_expect( (x), 0 )