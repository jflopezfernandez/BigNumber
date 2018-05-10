#ifndef BIGNUMBER_H_
#define BIGNUMBER_H_

#ifndef BIGNUMBER_LIBRARY
#define BIGNUMBER_API __declspec(dllimport)
#else
#define BIGNUMBER_API __declspec(dllexport)
#endif

#ifndef STDLIB_STRING_INCLUDED
#define STDLIB_STRING_INCLUDED
#include <string>
#endif // STDLIB_STRING_INCLUDED

class BigNumber
{

};

#endif // BIGNUMBER_H_