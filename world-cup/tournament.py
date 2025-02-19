# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO: Read teams into memory from file, each team has it's own dictionary with it's own rating
    filename = sys.argv[1]
    f = open(filename)
    team_and_rating = csv.DictReader(f)
    for team in team_and_rating:
        team["rating"] = int(team["rating"])
        teams.append(team)
    print(teams)

    counts = {}  # keeps track of the amount of times the team has won
    # TODO: Simulate N tournaments and keep track of win counts
    for i in range(N):
        team_that_won = simulate_tournament(teams)
        # if the team was already previously added to the dictionnary (if it had already won at least once)
        if team_that_won in counts:
            counts[team_that_won] += 1
        else:  # if it's the first time that team is winning
            counts[team_that_won] = 1
    print(counts)

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])
    return winners


def simulate_tournament(teams):  # returns the winner of an entire tournament
    """Simulate a tournament. Return name of winning team."""
    # TODO
    # while there isn't a single team
    while len(teams) > 1:
        # keep sending them to the simulate_round function, that will gradually eliminate teams and registar that as the new list of teams
        teams = simulate_round(teams)
    # there will be only one team left in the list
    return teams[0]["team"]


if __name__ == "__main__":
    main()
