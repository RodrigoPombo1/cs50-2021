from cs50 import get_string
from math import *

text =  get_string("Text: ")
length = len(text)
letter = 0
word = 0
sentence = 0
for i in range(length):
    char = text[i]
    if isalpha(char):
        letter += 1
        print(char)
    elif char == ' ':
        word += 1
    elif char == '!' or char == '?' or char == '.':
        sentence += 1
grade = round(0.0588 * float(letter) / float(word) * 100 - 0.296 * float(sentence) / float(word) * 100 - 15.8)

if 1 < grade < 16:
    print(f"Grade {grade}")
elif grade < 1:
    print("Before Grade 1")
else:
    print("Grade 16+")