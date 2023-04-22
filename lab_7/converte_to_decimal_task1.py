def converte_to_decimal(binary_list):
    degree = len(binary_list) - 1
    decimal_number = 0
    for binary_digit in binary_list:
        decimal_number += (2 ** degree) * binary_digit
        degree -= 1
    return decimal_number

words = [
"1 1 0 0 1 0 1 0 0 1 1 1 0 0 0 0",
"0 0 1 1 1 1 0 1 0 1 1 0 1 1 0 0",
"1 0 0 0 0 1 1 0 0 0 1 1 0 1 1 1",
"1 1 0 1 0 0 0 1 1 0 1 0 1 1 0 0",
"1 1 1 1 0 0 1 1 0 0 0 1 0 1 0 1",
"0 0 0 1 0 1 0 1 1 1 1 0 0 1 1 1",
"0 0 0 1 0 1 0 0 1 0 1 1 1 1 1 0",
"1 1 1 1 0 1 0 1 0 1 0 0 1 1 1 1",
"1 1 0 1 0 0 1 1 0 1 1 0 0 0 0 0",
"1 1 1 0 0 0 1 0 1 1 0 0 0 1 0 1",
"0 0 0 0 1 0 1 1 1 0 1 1 0 1 1 0",
"0 1 0 0 1 1 0 0 1 0 1 1 1 1 1 1",
"1 1 1 0 1 1 0 0 1 1 0 0 1 1 0 1",
"0 0 0 1 1 0 0 0 1 1 0 0 0 1 0 1",
"0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0",
"0 0 0 1 0 0 0 1 1 0 0 1 1 0 0 1"
]
test_word = "1 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0"
near_from_above = "1 1 0 0 1 0 1 0 0 1 1 1 0 0 0 0"
near_from_below = "1 0 0 0 0 1 1 0 0 0 1 1 0 1 1 1"

print("Test: ", converte_to_decimal([int(digit) for digit in test_word.split(" ")]))
print("Near from above: ", converte_to_decimal([int(digit) for digit in near_from_above.split(" ")]))
print("Near from below: ", converte_to_decimal([int(digit) for digit in near_from_below.split(" ")]))
print("Matrix")
for word in words:
    print(converte_to_decimal([int(digit) for digit in word.split(" ")]))
