/*
	Given a string, find the longest substring without repeating characters.
*/
import java.util.HashSet;
import java.util.Set;

class LongestSubstringWithoutRepeatingCharacters {

	public static String find(String str) {
		if (str.length() <= 1) {
			return str;
		}

		int start = 0;
		String result = "";
		Set<Character> char_set = new HashSet<>();

		for (int end = 0; end < str.length(); end++) {
			
			if (!char_set.contains(str.charAt(end))) {
				char_set.add(str.charAt(end));
				if ((end + 1 - start) > result.length()) {
					result = str.substring(start, end + 1);
				}
				continue;
			}

			while ( start < end) {
				if (str.charAt(start) != str.charAt(end)) {
					char_set.remove(str.charAt(start));
					start++;
				} else {
					start++;
					break;
				}
			}

		}

		return result;
	}

	public static void main(String[] args) {

		System.out.println(find("aabbaa").equals("ab") + " - " + find("aabbaa"));
		System.out.println(find("aabbbaa").equals("ab") + " - " + find("aabbbaa"));
		System.out.println(find("axcaxc").equals("axc") + " - " + find("axcaxc"));
		System.out.println(find("abcadbef").equals("cadbef") + " - " + find("abcadbef"));
		System.out.println(find("abkbcd").equals("kbcd") + " - " + find("abkbcd"));
		System.out.println(find("aaaaaa").equals("a") + " - " + find("aaaaaa"));
		System.out.println(find("pwwkew").equals("wke") + " - " + find("pwwkew"));
		System.out.println(find("abcabcbb").equals("abc") + " - " + find("abcabcbb"));

	}
}