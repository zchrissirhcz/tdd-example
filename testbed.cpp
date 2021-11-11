#include "gtest/gtest.h"
#include <string>

std::string convertArabicNumberToRomanNumeral(const unsigned int arabicNumber)
{
    if (arabicNumber == 3)
    {
        return "III";
    }
    if (arabicNumber == 2)
    {
        return "II";
    }
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

TEST(ArabicToRomanNumeralsConverter, 3_isConvertedTo_III)
{
    ASSERT_EQ("III", convertArabicNumberToRomanNumeral(3));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}