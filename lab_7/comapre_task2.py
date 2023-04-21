def compare(string1, string2):
    string1 = string1.replace(" ", "")
    string2 = string2.replace(" ", "")
    counter = 0
    for i in range(len(string1)):
        if string1[i] == string2[i]:
            counter += 1
    return counter

strs = [
"0 0 0 1 1 1 1 0 0 0 1 0 1 0 1 0 ",
"1 1 0 1 1 1 1 1 0 1 1 0 1 1 0 1 ",
"1 0 0 0 1 0 0 1 0 1 1 1 1 0 1 1 ",
"0 0 0 1 1 1 0 1 0 1 1 1 0 1 1 1 ",
"0 1 1 1 1 1 1 1 1 0 0 0 1 0 1 1 ",
"0 0 0 1 1 0 0 0 0 1 1 0 0 0 0 0 ",
"0 1 0 1 1 1 1 0 1 1 0 0 1 0 1 1 ",
"0 1 0 1 0 0 1 0 1 1 0 0 1 0 0 1 ",
"0 0 1 1 1 0 1 1 1 1 1 1 1 1 0 1 ",
"0 1 1 0 1 0 0 1 1 1 1 1 1 1 0 1"
]
str2 = "0 1 0 1 1 1 0 1 1 0 0 0 1 0 0 1"

for i in range(10):
    print(f"{i}:\t{compare(strs[i], str2)}")
