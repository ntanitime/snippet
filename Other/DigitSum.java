/*Implement a program, which given an integer n, computes the sum of its digits.

If a negative number is given, the function should work as if it was positive.

For example, if n is 1325132435356, the digit's sum is 43. If n is -10, the sum is 1 + 0 = 1.
https://www.hiredintech.com/classrooms/algorithm-design/lesson/76/task/27
*/
import java.util.List;

class DigitSum {
  public static int digit_sum(long number) {
    int result = 0;

    if (number <= -1) {
      number *= -1;
    }

    String str = String.valueOf(number);
    for (char c : str.toCharArray()) {
      result += Character.getNumericValue(c);
    }

    return result;
  }

  public static int digit_sum2(long number) {
    int sum = 0;
    if (number < 0) {
      number *= -1;
    }

    while (number > 0) {
      sum += number % 10;
      number /= 10;
    }

    return sum;
  }

  public static void main(String[] args) {
    long l = 110001108;

    System.out.println(digit_sum(l));
    System.out.println(digit_sum2(l));
  }
}
