import java.util.*;

public class Q5_1 {

	public static int updateBits(String _N, String _M, int j, int i) {
		int N = Integer.parseInt(_N, 2);
		int M = Integer.parseInt(_M, 2);

		System.out.println("N:  "+Integer.toBinaryString(N));
		System.out.println("M:  "+Integer.toBinaryString(M));

		int allOnes = ~0;
		int leftPart = allOnes << (j+1);
		int rightPart = (1 << i) - 1;

		int mask = leftPart | rightPart;
		System.out.println("mask:  "+Integer.toBinaryString(mask));

		N = N & mask;

		M = M << i;
		N = N | M;
		return N;
	}

	public static void main(String[] args) {
		int result = updateBits(
			"100000000000",
			"10011",
			6,
			2);
		System.out.println("result: "+Integer.toBinaryString(result));
	}

}