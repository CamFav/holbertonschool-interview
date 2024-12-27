#!/usr/bin/python3

def is_prime(num):
    """Check if a number is a prime number."""
    if num <= 1:
        return False
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return False
    return True

def generate_primes_up_to(n):
    """list of prime numbers up to n."""
    primes = []
    for i in range(2, n + 1):
        if is_prime(i):
            primes.append(i)
    return primes

def isWinner(x, nums):
    """
    winner of the prime game.

    Args:
        x: number of rounds
        nums: array of integers (n) ) represents the range 1 to n

    Returns:
        The name of the player that won the most rounds, or None if tied.
    """
    if x <= 0 or not nums:
        return None

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        primes = generate_primes_up_to(n)
        turn = 0  # 0, otherwise 1 for win

        while primes:
            chosen_prime = primes[0]
            primes = [p for p in primes if p % chosen_prime != 0]
            turn = 1 - turn

        # The player who cannot make a move lose
        if turn == 0:  # Maria win
            ben_wins += 1
        else:  # Ben win
            maria_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
