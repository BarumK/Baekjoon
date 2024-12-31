croatia_alphabet = ["dz=", "c=", "c-", "d-", "lj", "nj", "s=", "z="]
word = input()
word_num = len(word)
TF = False

for i in range(len(word) - 1):
    if TF == True:
        TF = False
    else:
        if i >= (len(word) - 2):
            if (word[i] + word[i + 1]) in croatia_alphabet:
                word_num -= 1
        else:
            if (word[i] + word[i + 1] + word[i + 2]) == "dz=":
                word_num -= 2
                TF = True
            elif (word[i] + word[i + 1]) in croatia_alphabet:
                word_num -= 1

print(word_num)