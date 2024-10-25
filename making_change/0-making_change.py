#!/usr/bin/python3

"""
    Given a pile of coins of different values,
    determine the fewest number of coins needed to meet a given amount total.

    Args:
        coins (list): Values of the coins in your possesssion.
        total (int): The target amount to reach using the
        minimum number of coins.

        Returns:
        int: The fewest number of coins needed to meet the total.
             Returns 0 if the total is 0 or less.
             Returns -1 if it is not possible to meet the
                        total with the given coins.
"""


def makeChange(coins, total):
    if total <= 0:
        return 0

    # Initialize array with infinity number
    nums = [float('inf') for x in range(total + 1)]

    # Make sure that 0 coins is needed for 0 dollars
    nums[0] = 0

    for coin in coins:
        for amount in range(len(nums)):
            # Check if the
            if coin <= amount:
                nums[amount] = min(nums[amount], 1 + nums[amount - coin])
    #
    return nums[total] if nums[total] != float('inf') else -1
