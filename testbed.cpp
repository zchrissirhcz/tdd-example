#include "gtest/gtest.h"
#include <string>
#include <array>

struct ArabicToRomanMapping
{
    unsigned int arabicNumber;
    std::string romanNumeral;
};

const std::size_t numberOfMappings = 3;
using ArabicToRomanMappings = std::array<ArabicToRomanMapping, numberOfMappings>;

const ArabicToRomanMappings arabicToRomanMappings = { {
    {100, "C"},
    {10, "X"},
    {1, "I"}
} };

std::string convertArabicNumberToRomanNumeral(unsigned int arabicNumber)
{
    std::string romanNumeral;
    while (arabicNumber >= arabicToRomanMappings[0].arabicNumber)
    {
        romanNumeral += arabicToRomanMappings[0].romanNumeral;
        arabicNumber -= arabicToRomanMappings[0].arabicNumber;
    }
    while (arabicNumber >= arabicToRomanMappings[1].arabicNumber)
    {
        romanNumeral += arabicToRomanMappings[1].romanNumeral;
        arabicNumber -= arabicToRomanMappings[1].arabicNumber;
    }
    while (arabicNumber >= arabicToRomanMappings[2].arabicNumber)
    {
        romanNumeral += arabicToRomanMappings[2].romanNumeral;
        arabicNumber -= arabicToRomanMappings[2].arabicNumber;
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
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}