"""
Program to calculate the Coleman-Liau index for a given text
"""

from cs50 import get_string


def main():
    text = get_string("Text: ")
    text_counts = count_text_components(text)
    score = calc_score(text_counts)
    print_grade(score)


def count_text_components(text):
    count = {"letters": 0, "words": 0, "sentences": 0}

    # counts the number of letters in the text
    # You may assume that a letter is any lowercase character from a to z or any uppercase character from A to Z
    for char in text:
        if char.isalpha():
            count["letters"] += 1

    # Count the number of words in the text
    # Any sequence of characters separated by spaces should count as a word
    for char in text:
        if char.isspace():
            count["words"] += 1
    count["words"] += 1  # To account for the last word that has no space after it.

    # Count the number of sentences in the text
    # Any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
    for char in text:
        if char in [".", "!", "?"]:
            count["sentences"] += 1

    return count


def calc_score(text_counts):
    L = text_counts["letters"] / text_counts["words"] * 100
    S = text_counts["sentences"] / text_counts["words"] * 100
    score = (0.0588 * L) - (0.296 * S) - 15.8

    return round(score)


def print_grade(score):
    if score < 1:
        print("Before Grade 1")
    elif score >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {score}")


if __name__ == "__main__":
    main()
