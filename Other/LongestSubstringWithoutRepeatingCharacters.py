from sets import Set

def longest_substring(s):
	if not s:
		return None

	start = 0
	end = 0

	longest = ''
	char_set = Set()

	while end < len(s):
		end += 1
		cur_char = s[end - 1]

		#print "cur_char: " + str(cur_char)
		if cur_char not in char_set:
			char_set.add(cur_char)
			#print char_set

			if end - start > len(longest):
				longest = s[start: end]
			
			#print "longest: " + str(longest)
			#print '------------------------'
			continue

		while start < end - 1:
			if s[start] != cur_char:
				char_set.remove(s[start])
				#print "*****Removing"
				#print s[start]
				#print char_set
				start += 1
			else:
				start += 1
				break
		#print "longest: " + str(longest)
		#print '------------------------'
	return longest;

print longest_substring("bacadbef")
print longest_substring("aabbaa")
print longest_substring("aabbbaa")
print longest_substring("axcaxc")
print longest_substring("abkbcd")
print longest_substring("aaaaaa")