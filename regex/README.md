## Description

This project involves implementing a function that checks whether a given pattern matches a given string. It explores basic concepts of regular expressions and aims to build an understanding of pattern matching logic.

---

### **Compilation Environment**  
- Ubuntu 14.04 LTS  
- gcc 4.8.4 with flags: `-Wall -Werror -Wextra -pedantic`

### **Coding Standards**  
- Use **Betty style**: validated with `betty-style.pl` and `betty-doc.pl`.  
- No global variables.  
- Maximum 5 functions per file.  
- All files must end with a new line.

---

### Tasks

Write a function to check whether a given pattern matches a given string.

**Prototype:** int regex_match(char const *str, char const *pattern);
Return 1 if it matches, 0 otherwise.

**Constraints:**

str supports all ASCII characters except . and *.
pattern supports all ASCII characters, including . and *.

### Example
The program matches strings like "H" with patterns like "H" or "H*". It supports advanced patterns like "Z'*'H.'*'", demonstrating the flexibility of regex.