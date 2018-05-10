/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 Jose Fernando Lopez Fernandez
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this
 * software and associated documentation files (the "Software"), to deal in the Software
 * without restriction, including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons
 * to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef BIGNUMBER_H_
#define BIGNUMBER_H_

/** @def BIGNUMBER_API
 *
 *  @description This macro determines whether the header file should declare
 *  the included functions as being imported or exported. By defining the
 *  macro BIGNUMBER_LIBRARY in the BigNumber.cc implementation file, we ensure that
 *  the BigNumber implementation functions are exported, while ensuring that
 *  the default for any client using the BigNumber library will correctly
 *  import the functions by default.
 *
 */

#ifndef BIGNUMBER_LIBRARY
#define BIGNUMBER_API __declspec(dllimport)
#else
#define BIGNUMBER_API __declspec(dllexport)
#endif

#ifndef STDLIB_IOSTREAM_INCLUDED
#define STDLIB_IOSTREAM_INCLUDED
#include <iostream>
#endif // STDLIB_IOSTREAM_INCLUDED

#ifndef STDLIB_STRING_INCLUDED
#define STDLIB_STRING_INCLUDED
#include <string>
#endif // STDLIB_STRING_INCLUDED

#ifndef STDLIB_STRING_VIEW_INCLUDED
#define STDLIB_STRING_VIEW_INCLUDED
#include <string_view>
#endif // STDLIB_STRING_VIEW_INCLUDED

#ifndef STDLIB_VECTOR_INCLUDED
#define STDLIB_VECTOR_INCLUDED
#include <vector>
#endif // STDLIB_VECTOR_INCLUDED

/** @class BigNumber [BigNumber.hxx]
 *
 *  @brief This class is meant to support arithmetic operations on integral
 *  values of arbitrary size and length, akin to Haskell's Int data type.
 *
 *  @description This class was created as a workaround to the constraints
 *  imposed by the built-in C++ type system.
 *
 */

class BIGNUMBER_API BigNumber
{
    std::string m_numberString;

public:
    /** @fn BigNumber()
     *
     *  @description This is the default constructor of the BigNumber class. It
     *  Constructs a BigNumber object with a value of zero (0).
     *
     */

    BigNumber();

    /** @fn BigNumber(const std::string_view& str)
     *
     *  @description This constructor replaces the first of the two original
     *  constructors in Mark Guerra's implementation of BigNumber. This
     *  constructor takes a string_view object, rather than a string, to prevent
     *  needless creation of a string value to pass to the constructor.
     *
     *  @description The constructor then initializes the m_numberString value
     *  in the constructor initializer list, rather than in the constructor body;
     *  another improvement over the original library.
     *
     */

    BigNumber(const std::string_view& str);

    /** @fn BigNumber(const long long& number)
     *
     *  @description The original BigNumber library passed the number parameter
     *  by value, but I decided to pass it by reference for consistency. A long long
     *  is a 64 bit value, same as the address of a long long, but I figured passing
     *  it as a const-reference would be most familiar to the C++ community.
     *
     */

    BigNumber(const long long& number);

    /** @fn isPositive() const noexcept
     *
     *  @description This function returns true if the BigNumber object in question
     *  is greater than zero, and false otherwise.
     *
     *  @returns <b>true</b> if (*this > 0)
     *  @returns <b>false</b> otherwise
     *
     *  @todo Implement bool BigNumber::isPositive() const noexcept
     *
     */

    bool isPositive() const noexcept;

    /** @fn bool isNegative() const noexcept
     *
     *  @description This function is essentially the opposite of isPositive(). It
     *  will return true if the object in question is less than zero (0).
     *
     *  @returns <b>true</b> if (*this < 0)
     *  @returns <b>false</b> otherwise
     *
     *  @note There are functions for testing whether the given object is either
     *  positive or negative, but not for testing whether it is zero. This is because
     *  the object is an integral type, and for checking if it's zero we will implement
     *  either the (!<object) functionality, or a simple operator == check.
     *
     *  @todo Implement bool BigNumber::isPositive() const noexcept
     *
     */

    bool isNegative() const noexcept;

    /** @fn BigNumber abs() const noexcept
     *
     *  @description This function returns the absolute value of the object in question.
     *  It creates a new BigNumber object on the stack, and with the implementation of
     *  operator overloadings, will allow for setting a new object to this object's
     *  absolute value. Also, it will allow for setting this object to its own absolute
     *  value with those same operator overloadings.
     *
     *  @returns BigNumber
     *
     */

    BigNumber abs() const noexcept;

    /** @fn std::string numberString() const noexcept
     *
     *  @description This function returns the internal string that holds the value of
     *  the BigNumber object.
     *
     *  @returns std::string
     *
     */

    std::string numberString() const noexcept;
};

#endif // BIGNUMBER_H_