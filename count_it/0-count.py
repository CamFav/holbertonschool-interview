#!/usr/bin/python3
import requests


def count_words(subreddit, word_list, after='', word_count={}):
    """
    Queries the Reddit API, parses the titles of all hot articles,
    and prints a sorted count of given keywords.

    Args:
        subreddit (str): The subreddit to search.
        word_list (list): The list of keywords to count.
        after (str): The 'after' parameter for pagination.
        word_count (dict): A dictionary to store the count of words.

    Returns:
        None
    """
    headers = {'User-Agent': 'myUserAgent'}
    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    params = {'limit': 100, 'after': after}

    response = requests.get(url, headers=headers, params=params,
                            allow_redirects=False)

    if response.status_code != 200:
        return

    data = response.json().get('data', {})
    after = data.get('after')

    posts = data.get('children', [])

    # Normalize word list
    word_list = [word.lower() for word in word_list]

    for post in posts:
        title = post.get('data', {}).get('title', '').lower()
        for word in word_list:
            word_count[word] = word_count.get(word, 0) + title.split().count(word)

    if after:
        return count_words(subreddit, word_list, after, word_count)
    else:
        if word_count:
            sorted_words = sorted(word_count.items(),
                                  key=lambda kv: (-kv[1], kv[0]))
            for word, count in sorted_words:
                if count > 0:
                    print(f'{word}: {count}')
