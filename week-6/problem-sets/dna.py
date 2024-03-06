import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) < 2:
        sys.exit("Too few command-line arguments")
    elif len(sys.argv) > 3:
        sys.exit("Too many command-line arguments")
    # TODO: Read database file into a variable
    # TODO: Read DNA sequence file into a variable
    else:
        with open(sys.argv[1]) as database:
            reader = csv.DictReader(database)
            databases = list(reader)
        with open(sys.argv[2]) as sequence:
            sequences = sequence.read()
    # TODO: Find longest match of each STR in DNA sequence
        matches = {}
        for i in databases[0]:
            matches[i] = longest_match(sequences, i)
    # TODO: Check database for matching profiles
        matched = 'No Match'
        for i in range(len(databases)):
            match_count = 1
            for j in matches:
                if str(matches[j]) == databases[i][j]:
                    match_count += 1
            if match_count == len(matches):
                matched = databases[i]['name']
                break
        print(matched)


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
