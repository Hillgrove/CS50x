"""
Word Frequency Counter:
Given a list of words, create a dictionary where the keys are the words,
and the values are the frequency of each word in the list.
"""

import sys

def main():

    wordcount = {}
    filename = sys.argv[1]
    with open(filename, "r") as file:
        for line in file:
            words = line.split()
            for word in words:
                if word not in wordcount:
                    wordcount[word] = 1
                else:
                    wordcount[word] += 1

    for word in wordcount:
        print(f"{word}: {wordcount[word]}")



if __name__ == "__main__":
    main()