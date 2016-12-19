import java.io.*;
import java.util.*;

public class Solution001_1 {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();

        int[] numbers = new int[n];
        for (int i = 0; i < n; i++) {
            numbers[i] = s.nextInt();
        }

        System.out.println(solution(numbers));
    }

    public static int solution(int[] arr) {
        int counter = 0;
        int n = arr.length;

        for (int i = 0; i < n; i++) {
            int totalSum = arr[i];
            if (totalSum < 0) {
                counter++;
            }

            for (int j = i + 1; j < n; j++) {
                totalSum += arr[j];

                if (totalSum < 0) {
                    counter++;
                }
            }
        }

        return counter;
    }
}

// https://www.hackerrank.com/challenges/java-negative-subarray
// Time O(n^2)