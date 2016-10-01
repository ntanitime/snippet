/*

A sequence of numbers is called a zig-zag sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a zig-zag sequence.

For example, 1,7,4,9,2,5 is a zig-zag sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, 1,4,7,2,5 and 1,7,4,5,5 are not zig-zag sequences, the first because its first two differences are positive and the second because its last difference is zero.

Given a sequence of integers, sequence, return the length of the longest subsequence of sequence that is a zig-zag sequence. A subsequence is obtained by deleting some number of elements (possibly zero) from the original sequence, leaving the remaining elements in their original order.
https://community.topcoder.com/stat?c=problem_statement&pm=1259&rd=4493&rm=&cr=107835
*/
import java.util.List;
import java.util.Arrays;

public class ZigZag {

	//Compact function
	public static int zigZag(List<Integer> l) {
		if (l.size() <= 1) {
			return l.size();
		}

		boolean upDown = true; //Ex. 7-3 (Up-Dwon)
		int result = 1;//The first node is +1

		int firstElem = l.get(0);
		int lastElem = -1;

		for (int i = 1; i < l.size(); i++) {

			//Need to detect the ZigZag trend (only one time)
			if (lastElem == -1) {
				if (firstElem == l.get(i)) {
					continue;
				}

				lastElem = l.get(i);
				if (firstElem > l.get(i)) {
					upDown = true;
				} else {
					upDown = false;
				}
				result++;
				continue;
			}

			//Now upDown is set correctly
			//Scan here from elem >= 3
			if (lastElem == l.get(i)) {
				continue;
			}

			if (upDown) {
				if (lastElem < l.get(i)) {
					result++;
					upDown = false;
				}
			} else {
				if (lastElem > l.get(i)) {
					result++;
					upDown = true;
				}
			}

			lastElem = l.get(i);
		}

		return result;
	}

	public static int zigZag2(List<Integer> l) {
		if (l.size() <= 1) {
			return l.size();
		}

		boolean upDown = true; //Ex. 7-3 (Up-Dwon)
		int result = 1;//The first node is +1

		int firstElem = l.get(0);
		int lastElem = -1;

		//Need to take the start trend of ZigZag
		int i = 1;
		for (; i < l.size(); i++) {
			if (firstElem == l.get(i)) {
				continue;
			}

			lastElem = l.get(i);
			if (firstElem > l.get(i)) {
				upDown = true;
			} else {
				upDown = false;
			}

			result++;
			break;
		}

		//Scan the other part of the list
		for (int j = i; j < l.size(); j++) {
			if (lastElem == l.get(j)) {
				continue;
			}

			if (upDown) {
				if (lastElem < l.get(j)) {
					result++;
					upDown = false;
				}
			} else {
				if (lastElem > l.get(j)) {
					result++;
					upDown = true;
				}
			}

			lastElem = l.get(j);
		}

		return result;
	}

	public static void main(String[] args) {
		System.out.println("Starting...");
		//List<Integer> list = Arrays.asList(1, 7, 4, 9, 2, 5);
		System.out.println(zigZag(Arrays.asList(1, 7, 4, 9, 2, 5)) == 6);
		System.out.println(zigZag(Arrays.asList(1, 17, 5, 10, 13, 15, 10, 5, 16, 8)) == 7);
		System.out.println(zigZag(Arrays.asList(10, 20)) == 2);
		System.out.println(zigZag(Arrays.asList(20, 20)) == 1);
		System.out.println(zigZag(Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9)) == 2);
		System.out.println(zigZag(Arrays.asList(10, 9, 8, 7, 6, 7, 8, 9, 10)) == 3);
		System.out.println(zigZag(Arrays.asList(12, 333, 700, 436, 1, 919, 959, 456, 456, 456, 1000, 193, 192, 13, 75, 818, 197, 197, 2, 777, 99, 81, 222, 109, 1000, 19, 27, 270, 62, 189, 987, 234, 55, 2, 718, 238, 901, 901, 900, 432, 55, 606, 89, 7, 7, 23, 789, 790, 800, 1000)) == 26);
		System.out.println(zigZag(Arrays.asList(70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32)) == 8);
		System.out.println(zigZag(Arrays.asList(4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2)) == 3);
		System.out.println(zigZag(Arrays.asList(1, 2, 2, 1, 1, 2, 3, 3, 2, 1, 1, 2, 3, 4, 4, 3, 2, 1, 1, 2, 3, 4, 5, 5, 4, 3, 2, 1)) == 9);
		System.out.println(zigZag(Arrays.asList(396, 549, 22, 819, 611, 972, 730, 638, 978, 342, 566, 514, 752, 871, 911, 172, 488, 542, 482, 974, 210, 474, 66, 387, 1, 872, 799, 262, 567, 113, 578, 308, 813, 515, 716, 905, 434, 101, 632, 450, 74, 254, 1000, 780, 633, 496, 513, 772, 925, 746)) == 37);
		System.out.println(zigZag(Arrays.asList(374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 249, 22, 176, 279, 23, 22, 617, 462, 459, 244)) == 36);
		System.out.println(zigZag(Arrays.asList(89, 106, 125, 142, 141, 137, 158, 184, 191, 189, 189, 206, 228, 240, 228, 263, 259, 256, 266, 287, 302, 297, 330, 341, 353, 353, 364, 376, 365, 398, 386, 420, 413, 419, 451, 441, 463, 484, 480, 487, 494, 520, 534, 542, 534, 541, 571, 584, 565, 577)) == 26);
		System.out.println(zigZag(Arrays.asList(61, 82, 126, 97, 167, 186, 119, 154, 155, 142, 153, 181, 172, 192, 223, 272, 273, 260, 280, 330, 329, 350, 273, 324, 349, 306, 385, 375, 420, 416, 435, 457, 373, 477, 395, 487, 500, 439, 493, 537, 518, 549, 542, 500, 524, 541, 512, 589, 549, 543)) == 35);
		System.out.println(zigZag(Arrays.asList(4, 1, 6, 7, 7, 8, 9, 8, 6, 8)) == 5);
		System.out.println(zigZag(Arrays.asList(9, 1, 8, 2, 7, 3, 6, 4, 5, 5, 4, 6, 3, 7, 2, 8, 1, 9)) == 17);
	}

}