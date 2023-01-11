/*
 * Valid Number
 *
 * Validate if a given string is numeric.
 *
 * Some examples:
 *
 *    "0"     => true
 *    " 0.1 " => true
 *    "abc"   => false
 *    "1 a"   => false
 *    "2e10"  => true
 *
 * Note: It is intended for the problem statement to be ambiguous. You should
 * gather all requirements up front before implementing one.
 */

#include <cctype>
#include <iostream>

using namespace std;

class Solution {
 public:
  bool isNumber2(const char *s) {
    bool space  = false;
    bool digit = false;
    bool left_digit = false;
    bool right_digit = false;
    bool period = false;
    bool left_sign = false;
    bool right_sign = false;
    bool exponent = false;

    // Skip leading spaces
    const char *p = s;
    while (*p == ' ') {
      ++p;
    }

    for (; *p != '\0'; ++p) {
      if (isspace(*p)) {
        space = true;
      } else if (isdigit(*p) && !space) {
        if (!exponent) left_digit = true;
        else right_digit = true;
        digit = true;
      } else if (*p == '.' && !period && !space && !exponent) {
        period = true;
      } else if (*p == '+' || *p == '-') {
        if (!digit && !exponent && !left_sign && !period)
          left_sign = true;
        else if (exponent && !right_sign && !right_digit)
          right_sign = true;
        else
          return false;
      } else if ((*p == 'e' || *p == 'E') && left_digit && !exponent) {
        exponent = true;
      } else {
        return false;
      }
    }
    if (!digit || (exponent && !right_digit)) {
      return false;
    }
    return true;
  }

  bool isNumber(const char *s) {
    bool result(false);
    if (*s =='\0') return result;
    bool hasNum(false), hasDot(false), hasE(false), hasSpace(false), hasSign(false);
    const char *p(s);
    // Skip leading whitespaces
    while (*p != '\0' && *p == ' ') {
      ++p;
    }
    if (*p == '\0') {
      return false;
    }
    for (; *p != '\0'; ++p) {
      if (*p == 'e' || *p == 'E') {
        if (hasE || hasSpace || !hasNum) {
          return false;
        }
        hasE = true;
        hasNum = false;
        hasSign = false;
      }
      else if (*p == '+' || *p == '-') {
        if (hasSign || hasNum || hasSpace) {
          return false;
        }
        hasSign = true;
      } else if ( *p == '.') {
        if (hasDot || hasE ||hasSpace) {
          return false;
        }
        hasDot = true;
      } else if (*p == ' ')
        hasSpace = true;
      else if (*p <= '9' && *p >= '0') {
        if (hasSpace) {
          return false;
        }
        hasNum = true;
      }
      else {
        return false;
      }
    }
    if (hasNum) return true;
    return false;
  }

  bool isNumber(const char *s) {
    const char *p = s;
    int state = 0;
    while (*p != '\0') {
      switch (state) {
        case 0:
          if (isspace(*p)) state = 0;
          else if (isdigit(*p)) state = 1;
          else if (*p == '.') state = 2;
          else if (*p == '+' || *p == '-') state = 3;
          else return false;
          break;
        case 1:
          if (isdigit(*p)) state = 1;
          else if (*p == '.') state = 4;
          else if (*p == 'e' || *p == 'E') state = 5;
          else if (isspace(*p)) state = 8;
          else return false;
          break;
        case 2:
          if (isdigit(*p)) state = 4;
          else return false;
          break;
        case 3:
          if (isdigit(*p)) state = 1;
          else if (*p == '.') state = 2;
          else return false;
          break;
        case 4:
          if (isdigit(*p)) state = 4;
          else if (*p == 'e' || *p == 'E') state = 5;
          else if (isspace(*p)) state = 8;
          else return false;
          break;
        case 5:
          if (*p == '+' || *p == '-') state = 6;
          else if (isdigit(*p)) state = 7;
          else return false;
          break;
        case 6:
          if (isdigit(*p)) state = 7;
          else return false;
          break;
        case 7:
          if (isdigit(*p)) state = 7;
          else if (isspace(*p)) state = 8;
          else return false;
          break;
        case 8:
          if (isspace(*p)) state = 8;
          else return false;
          break;
      }
      ++p;
    }
    return state == 1 || state == 4 || state == 7 || state == 8;
  }

  bool isNumber3(const char *s) {
    enum InputType {
      OTHER,      // 0
      SPACE,      // 1
      SIGN,       // 2
      DIGIT,      // 3
      DOT,        // 4
      EXPONENT,   // 5
      NUM_INPUTS  // 6
    };
    int transitionTable[][NUM_INPUTS] = {
      -1,  0,  3,  1,  2, -1, // next states for state 0
      -1,  8, -1,  1,  4,  5, // next states for state 1
      -1, -1, -1,  4, -1, -1, // next states for state 2
      -1, -1, -1,  1,  2, -1, // next states for state 3
      -1,  8, -1,  4, -1,  5, // next states for state 4
      -1, -1,  6,  7, -1, -1, // next states for state 5
      -1, -1, -1,  7, -1, -1, // next states for state 6
      -1,  8, -1,  7, -1, -1, // next states for state 7
      -1,  8, -1, -1, -1, -1, // next states for state 8
    };

    int state = 0;
    while (*s != '\0') {
      InputType inputType = OTHER;
      if (isspace(*s))
        inputType = SPACE;
      else if (*s == '+' || *s == '-')
        inputType = SIGN;
      else if (isdigit(*s))
        inputType = DIGIT;
      else if (*s == '.')
        inputType = DOT;
      else if (*s == 'e' || *s == 'E')
        inputType = EXPONENT;

      // Get next state from current state and input symbol
      state = transitionTable[state][inputType];

      // Other input
      if (state == -1) return false;

      ++s;
    }

    // If the current state belongs to one of the accepting states,
    // then the number is valid
    return state == 1 || state == 4 || state == 7 || state == 8;
  }
};

int main(int argc, char **argv) {
  Solution sln;
  string line;
  while (getline(cin, line)) {
    cout << sln.isNumber(line.c_str()) << endl;
  }
  return 0;
}
