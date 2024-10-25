# Make Change

Determine the fewest number of coins needed to meet a given total amount.

## Function Prototype

```
def makeChange(coins, total):
    """
    Parameters:
    coins (list): Coin values available.
    total (int): Target amount.

    Returns:
    int: Fewest number of coins to meet total or -1 if not possible.
    """
```

## Installation & Usage

No installation needed. Just clone and run:

```
git clone https://github.com/yourusername/make_change.git
cd make_change
```

Use with Python:

```
from make_change import makeChange

print(makeChange([1, 5, 10, 25], 63))  # Output: 6
```

## Examples

```
makeChange([1, 5, 10, 25], 63)  # Returns: 6
makeChange([2, 5, 10], 7)       # Returns: -1
makeChange([1, 3, 4], 6)        # Returns: 2
```

## Contributing

1. Fork the repository.
2. Create a branch (git checkout -b feature/feature-name).
3. Commit your changes (git commit -m 'Add feature').
4. Push (git push origin feature-name).
5. Open a Pull Request.
