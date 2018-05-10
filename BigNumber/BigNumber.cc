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

#define BIGNUMBER_LIBRARY

#include <BigNumber/BigNumber.hxx>

BigNumber::BigNumber()
    : m_numberString { "0" } { }

BigNumber::BigNumber(const std::string_view& str)
    : m_numberString { str } { }

BigNumber::BigNumber(const long long& number)
    : m_numberString { std::to_string(number) } { }

bool BigNumber::isPositive() const noexcept
{
    // TODO: Implement bool BigNumber::isPositive() const noexcept
    return false;
}

bool BigNumber::isNegative() const noexcept
{
    // TODO: Implement bool BigNumber::isNegative() const noexcept
    return false;
}

BigNumber BigNumber::abs() const noexcept
{
    // TODO: Implement BigNumber BigNumber::abs() const noexcept
    return false;
}

std::string BigNumber::numberString() const noexcept
{
    return m_numberString;
}

long long BigNumber::value() const noexcept
{
    // Need to implement operator > to do:
    // if BigNumber { LONG_LONG_MAX } > *this
    //     return -1
    // else
    //     return ...

    // TODO: Need to do error/bounds checking
    const auto value = std::stoll(numberString());

    return value;
}

bool operator>(const BigNumber& a, const BigNumber& b)
{
    if (a.value() > b.value())
    {
        return true;
    }

    return false;
}
