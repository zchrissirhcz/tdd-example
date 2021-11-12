#include "gtest/gtest.h"
#include <string>
#include <array>

struct ArabicToRomanMapping
{
    unsigned int arabicNumber;
    std::string romanNumeral;
};

const std::size_t numberOfMappings = 11;
using ArabicToRomanMappings = std::array<ArabicToRomanMapping, numberOfMappings>;

const ArabicToRomanMappings arabicToRomanMappings = { {
    {1000, "M"},
    {500, "D"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"}
} };

std::string convertArabicNumberToRomanNumeral(unsigned int arabicNumber)
{
    std::string romanNumeral;
    for (const auto& mapping: arabicToRomanMappings)
    {
        while (arabicNumber >= mapping.arabicNumber)
        {
            romanNumeral += mapping.romanNumeral;
            arabicNumber -= mapping.arabicNumber;
        }
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
    assertThat(100).isConvertedToRomanNumeral("C");
    assertThat(200).isConvertedToRomanNumeral("CC");
    assertThat(300).isConvertedToRomanNumeral("CCC");
    assertThat(1000).isConvertedToRomanNumeral("M");
    assertThat(5).isConvertedToRomanNumeral("V");
    assertThat(6).isConvertedToRomanNumeral("VI");
    assertThat(37).isConvertedToRomanNumeral("XXXVII");
    assertThat(50).isConvertedToRomanNumeral("L");
    assertThat(500).isConvertedToRomanNumeral("D");
    assertThat(4).isConvertedToRomanNumeral("IV");
    assertThat(9).isConvertedToRomanNumeral("IX");
    assertThat(40).isConvertedToRomanNumeral("XL");
    assertThat(90).isConvertedToRomanNumeral("XC");
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}