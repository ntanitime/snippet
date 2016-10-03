/*
A palindrome is а word or a phrase or a number, that when reversed, stays the same.

For example, the following sequences are palindromes : "azobi4amma4iboza" or "anna".

But this time, we are not interested in words but numbers. A "number palindrome" is a number, that taken backwards, remains the same.

For example, the numbers 1, 4224, 9999, 1221 are number palindromes.

Implement a function, which given an integer computes if it's a palindrome.
https://www.hiredintech.com/classrooms/algorithm-design/lesson/76/task/29
*/
class NumericPalindromes {
  public static boolean is_numeric_palindrome(long number) {
    String str = String.valueOf(number);
    int length = str.length();
    boolean result = true;

    for (int i = 0; i < length / 2; i++) {
      if (str.charAt(i) != str.charAt(length - i - 1)) {
        result = false;
        break;
      }
    }

    return result;
  }

  public static void main(String[] args) {
    long l = 99899;

    System.out.println(is_numeric_palindrome(l));
  }
}