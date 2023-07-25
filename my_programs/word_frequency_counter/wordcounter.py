"""
Word Frequency Counter:
Given a list of words, create a dictionary where the keys are the words,
and the values are the frequency of each word in the list.
"""

from collections import Counter
import sys


def main():

    wordcount = {}
    filename = sys.argv[1]
    with open(filename, "r") as file:
        words = file.read().split()
        wordcount = Counter(words)

    for word in wordcount:
        print(f"{word}: {wordcount[word]}")



if __name__ == "__main__":
    main()