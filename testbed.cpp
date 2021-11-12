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

class RomanNumeralAssert {
public:
    RomanNumeralAssert() = delete;
    explicit RomanNumeralAssert(const unsigned int _arabicNumber) : 
        arabicNumber(_arabicNumber) {}
    void isConvertedToRomanNumeral(const std::string& expectedRomanNumeral) const {
        ASSERT_EQ(expectedRomanNumeral, convertArabicNumberToRomanNumeral(arabicNumber));
    }
private:
    const unsigned int arabicNumber;
};

RomanNumeralAssert assertThat(const unsigned int arabicNumber)
{
    RomanNumeralAssert assert{arabicNumber};
    return assert;
}

TEST(ArabicToRomanNumeralsConverter, many_cases)
{
    assertThat(1).isConvertedToRomanNumeral("I");
    assertThat(2).isConvertedToRomanNumeral("II");
    assertThat(3).isConvertedToRomanNumeral("III");
    assertThat(10).isConvertedToRomanNumeral("X");
    assertThat(20).isConvertedToRomanNumeral("XX");
    assertThat(30).isConvertedToRomanNumeral("XXX");
    assertThat(33).isConvertedToRomanNumeral("XXXIII");
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}