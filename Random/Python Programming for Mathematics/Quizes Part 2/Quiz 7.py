""" Create a function called count_dog that counts the number of times the word "dog" occurs in a string. 
Don't worry about edge cases like punctuation being attached to the word "dog", but account for capitalization.

E.g., count_dog("This dog runs faster than the other dog dude!") should return 2.

Hint: Make use of the string methods .lower() and .split(). """


def count_dog(str):
    count = 0
    split = str.split()
    for i in range(len(split)):
        if split[i].lower() == "dog":
            count += 1
    return count
