
#include <fstream>
#include <iostream>
#include <limits>

#define CATCH_CONFIG_RUNNER
#include <Catch/catch.hpp>

#include <BigNumber/BigNumber.hxx>

#ifdef ENABLE_GMP
#include <boost/multiprecision/gmp.hpp>
#endif

/** @test This test checks the string representation functions of the BigNumber
 *  class to make sure created BigNumber objects correctly represent their
 *  numerical value, despite the fact the data is internally stored as a string,
 *  rather than a numerical value.
 *
 */

TEST_CASE("BigNumber String Representation", "[String Representation]")
{
    REQUIRE(BigNumber { }.numberString() == "0");
    REQUIRE(BigNumber { "127" }.numberString() == "127");
    REQUIRE(BigNumber { -17 }.numberString() == "-17");
}

/** @test This test checks to make sure the numeric value of the BigNumber
 *  object matches up with the textual representation stored internally.
 *
 */

TEST_CASE("BigNumber Numeric Value", "[Numeric Value]")
{
    REQUIRE(BigNumber { }.value() == 0);
    REQUIRE(BigNumber { "127" }.value() == 127);
    REQUIRE(BigNumber { INT_MAX }.value() == INT_MAX);
    REQUIRE(BigNumber { LLONG_MAX }.value() == LLONG_MAX);
    
    /** @test This particular test case aims to find out if the BigNum numeric 
     *  value is greater than long long max. If it is, it will return -1. Otherwise,
     *  it will return the numeric value as a long long.
     *
     *  @todo Implement REQUIRE(BigNumber { LLONG_MAX + 1 }.value() == -1) test case
     *
     */

    // TODO: Implement this test case to ensure BigNum can transform to long long
    //REQUIRE(BigNumber { LLONG_MAX + 1 }.value() == -1);
}

/** @fn int main(int argc, char *argv[])
 *
 *  @description This is the main function for the Catch test framework. It will
 *  run all the defined test cases and return successfully if all tests passes,
 *  or it will abort on the first test failed.
 *
 *  @returns int
 *
 */

int main(int argc, char *argv[])
{
    return Catch::Session().run(argc, argv);
}
