#include "gtest/gtest.h"
#include <string>

std::string convertArabicNumberToRomanNumeral(const unsigned int arabicNumber)
{
    return "I";
}

TEST(ArabicToRomanNumeralsConverter, PreparationsCompleted)
{
    GTEST_SUCCEED();
}

TEST(ArabicToRomanNumeralsConverter, 1_isConvertedTo_I)
{
    ASSERT_EQ("I", convertArabicNumberToRomanNumeral(1));
}

TEST(ArabicToRomanNumeralsConverter, 2_isConvertedTo_II)
{
    ASSERT_EQ("II", convertArabicNumberToRomanNumeral(2));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}