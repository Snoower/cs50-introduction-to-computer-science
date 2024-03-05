def main():
    text = input("Text: ")
    L = float(count_letters(text) / count_words(text)) * 100.00
    S = float(count_sentences(text) / count_words(text)) * 100.00
    index = round((0.0588 * L) - (0.296 * S) - 15.8)
    if index >= 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {index}")


def count_letters(text):
    count = 0
    for char in text:
        if char.isalpha():
            count += 1
    return count


def count_words(text):
    # Accounts for the last word (i.e. without count=1, 'how are you' counts as two whereas 'how are you ' counts as three.)
    count = 1
    i = 0
    n = len(text)
    while i < n:
        if text[i] == ' ' or text[i] == '\n':
            while i + 1 < n and (text[i+1] == ' ' or text[i+1] == '\n'):
                i += 1
            count += 1
        i += 1
    return count


def count_sentences(text):
    count = 0
    i = 0
    n = len(text)
    while i < n:
        if text[i] == '.' or text[i] == '!' or text[i] == '?':
            count += 1
        i += 1
    return count


if __name__ == "__main__":
    main()
