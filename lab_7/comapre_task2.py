def compare(string1, string2):
    string1 = string1.replace(" ", "")
    string2 = string2.replace(" ", "")
    counter = 0
    for i in range(len(string1)):
        if string1[i] == string2[i]:
            counter += 1
    return counter

strs = [
"0 0 1 0 1 1 0 1 0 0 0 0 0 0 1 0", 
"0 1 0 1 0 1 1 0 1 1 0 0 0 0 0 0", 
"0 1 1 1 1 1 1 1 1 1 1 1 0 1 0 0", 
"0 0 1 0 1 1 1 0 0 1 1 0 1 1 0 1", 
"0 1 0 1 0 1 1 1 1 0 1 1 1 1 1 0", 
"1 0 0 0 1 1 0 1 0 1 1 1 0 0 0 1", 
"1 1 0 0 0 1 1 1 0 0 0 1 1 1 1 0", 
"0 0 0 1 1 1 1 0 0 0 1 1 0 0 0 0", 
"1 0 0 1 0 1 1 0 0 1 1 1 1 1 0 1", 
"1 0 0 0 1 1 0 0 0 0 1 0 0 1 0 1", 
"1 0 0 1 0 1 1 0 1 1 1 0 0 1 1 1", 
"0 1 1 1 1 0 1 1 0 0 1 0 1 0 1 1", 
"0 1 0 0 1 0 0 0 1 0 0 1 1 1 0 1", 
"0 1 1 1 1 0 0 1 1 0 1 0 0 0 1 0", 
"0 0 1 1 0 1 1 1 1 1 0 1 0 0 0 0",
"1 1 0 1 0 0 0 1 0 0 1 0 0 1 1 0"
]
str2 = "1 0 1 1 1 0 0 1 1 0 0 1 0 0 0 1"

for i in range(16):
    print(f"{i}:\t{compare(strs[i], str2)}")

answer = "1 0 0 0 1 1 0 1 0 1 1 1 0 0 0 1"
for i in range(16):
    print(i, answer == strs[i])
