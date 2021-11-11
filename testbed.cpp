#include "gtest/gtest.h"
#include <string>

std::string convertArabicNumberToRomanNumeral(unsigned int arabicNumber)
{
    std::string romanNumeral;
    while(arabicNumber >= 10)
    {
        romanNumeral += "X";
        arabicNumber -= 10;
    }
    while (arabicNumber >= 1)
    {
        romanNumeral += "I";
        arabicNumber--;
    }
    return romanNumeral;
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

TEST(ArabicToRomanNumeralsConverter, 3_isConvertedTo_III)
{
    ASSERT_EQ("III", convertArabicNumberToRomanNumeral(3));
}

TEST(ArabicToRomanNumeralsConverter, 10_isConvertedTo_X)
{
    ASSERT_EQ("X", convertArabicNumberToRomanNumeral(10));
}

TEST(ArabicToRomanNumeralsConverter, 20_isConvertedTo_XX)
{
    ASSERT_EQ("XX", convertArabicNumberToRomanNumeral(20));
}

TEST(ArabicToRomanNumeralsConverter, 10_isConvertedTo_XXX)
{
    ASSERT_EQ("XXX", convertArabicNumberToRomanNumeral(30));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}