
#include <fstream>
#include <iostream>

#define CATCH_CONFIG_RUNNER
#include <Catch/catch.hpp>

#include <BigNumber/BigNumber.hxx>

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
