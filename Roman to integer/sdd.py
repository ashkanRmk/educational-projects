import sys
from collections import OrderedDict

letterValues = {
    'M': 1000,
    'D': 500,
    'C': 100,
    'L': 50,
    'X': 10,
    'V': 5,
    'I': 1
}


def value_of_roman_letter(ch):
    """Return the value associated with a single Roman numeral letter."""
    try:
        return letterValues[ch.upper()]
    except KeyError:
        print("error: invalid Roman numeral character " + str(ch))
        sys.exit(1)


def int_from_roman_numeral(s):
    """Return the integer value of the given Roman numeral string."""
    result = 0
    lastValue = sys.maxsize
    for ch in s:
        value = value_of_roman_letter(ch)
        if value > lastValue:
            # We've found something like "IV" or "IX"
            # or "XC".  Need to undo the addition
            # of the previous value, then add
            # (value - lastValue) to the result.
            result += value - 2 * lastValue
        else:
            result += value
        lastValue = value
    return result


def write_roman(num):
    num = int(num)
    roman = OrderedDict()
    roman[1000] = "M"
    roman[900] = "CM"
    roman[500] = "D"
    roman[400] = "CD"
    roman[100] = "C"
    roman[90] = "XC"
    roman[50] = "L"
    roman[40] = "XL"
    roman[10] = "X"
    roman[9] = "IX"
    roman[5] = "V"
    roman[4] = "IV"
    roman[1] = "I"

    def roman_num(num):
        for r in roman.keys():
            x, y = divmod(num, r)
            yield roman[r] * x
            num -= (r * x)
            if num > 0:
                roman_num(num)
            else:
                break

    return "".join([a for a in roman_num(num)])


def is_number(s):
    try:
        float(s)
        return True
    except ValueError:
        return False


def input_loop():
    """Repeatedly prompt user for a Roman numeral and print the integer value."""
    while True:
        userInput = input("Enter a Roman or Integer numeral: ").strip()
        if len(userInput) == 0:
            sys.exit(0)

        if is_number(userInput):
            print(str(userInput) + " = " + str(write_roman(userInput)))
        else:
            intValue = int_from_roman_numeral(userInput)
            print(str(userInput) + " = " + str(intValue))

if __name__ == '__main__':
    input_loop()
