import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    filename = sys.argv[1]
    f = open(filename)
    data = csv.DictReader(f)
    keys = data.fieldnames

    # convert the number of times the DNA appears to an int
    for person in data:
        for key in keys:
            if key != "name":
                person[key] = int(person[key])

    # TODO: Read DNA sequence file into a variable
    filename = sys.argv[2]
    f = open(filename)
    sequence = csv.reader(f)

    # TODO: Find longest match of each STR in DNA sequence
    longest_matching = []
    for key in keys:
        if key != "name":
            for sequence1 in sequence: #it's only one sequence
                continue
            longest_matching.append(longest_match(sequence1[0], key))

    # TODO: Check database for matching profiles
    filename = sys.argv[1]
    f = open(filename)
    data = csv.DictReader(f)
    # it's necessary to open it again because it has already gone through it once and that uses it up
    # I could have also stored the values into a list in the first time and use the list now
    for person in data:
        counter = 0
        matches = 0
        for key in keys:
            if key != "name":
                person[key] = int(person[key])
                # it's necessary to convert the string to a an int just like we did the first time
                if person[key] == longest_matching[counter]:
                    matches += 1
                counter += 1
        if matches == len(keys) - 1:
            print(person["name"])
            return
    print("No match")
    return


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
