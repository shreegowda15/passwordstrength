# passwordstrength
Check the strength of the password using array data structures
# Password Strength Checker in C

A console-based Password Strength Checker built in C that evaluates the strength of a password using length, character variety, common password detection, sequential pattern detection, and entropy calculation.

## Features

* Checks if the password is at least 8 characters long.
* Detects:

  * Lowercase letters
  * Uppercase letters
  * Digits
  * Special characters
* Detects common passwords (e.g., `123456`, `password`, `qwerty`).
* Detects sequential patterns like `abc`, `123`, or `cba`.
* Calculates password entropy in bits.
* Generates a password strength score out of **100**.
* Classifies passwords as:

  * Very Weak
  * Weak
  * Medium
  * Strong
  * Very Strong
* Provides hints to improve weak passwords.

## Technologies Used

* **Language:** C
* **Libraries Used:**

  * `stdio.h`
  * `string.h`
  * `ctype.h`
  * `math.h`

## Data Structures Used

* Character arrays (strings) for storing passwords.
* Array of strings for storing common passwords.
* Integer and double variables for score and entropy calculations.

## Project Structure

```text
passwordstrength/
├── passwordstrength.c
└── README.md
```

## How to Compile

```bash
gcc passwordstrength.c -o passwordstrength.exe -lm
```

## How to Run

### Windows (PowerShell)

```powershell
.\passwordstrength.exe
```

### Linux/macOS

```bash
./passwordstrength
```

## Sample Output

```text
Enter password (or type 'exit' to quit): Hello@123

Score   : 79 / 100
Strength: Strong
Entropy : 72.45 bits

Hints:
```

## How the Strength Score is Calculated

| Criterion             |    Contribution |
| --------------------- | --------------: |
| Password Length       | Up to 45 points |
| Lowercase Letters     |        8 points |
| Uppercase Letters     |        8 points |
| Digits                |        8 points |
| Special Characters    |       10 points |
| No Sequential Pattern |       10 points |
| Not a Common Password |       10 points |
| Entropy ≥ 60 bits     |       10 points |

## Future Improvements

* Detect repeated character patterns.
* Suggest stronger passwords automatically.
* Check passwords against leaked password databases.
* Build a graphical user interface (GUI) version.

## Author

**Shree Gowda**

5th Semester Information Science Engineering Student
