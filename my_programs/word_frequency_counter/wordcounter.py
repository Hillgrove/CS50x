"""
Word Frequency Counter:
Given a list of words, create a dictionary where the keys are the words,
and the values are the frequency of each word in the list.
"""

from collections import Counter
import sys


def main():

    filename = sys.argv[1]
    with open(filename, "r", encoding="iso-8859-1") as file:
        words = file.read().split()
        wordcount = Counter(words)

    print(f"Top 10 words used in '{filename}':")
    for word, count in wordcount.most_common(10):
        print(word, count)


if __name__ == "__main__":
    main()