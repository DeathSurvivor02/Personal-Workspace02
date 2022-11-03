# Compute a (simplified) Pig Latin version of a word.

###################################################
# Pig Latin formula

from asyncio import constants


def pig_latin(word):
	"""Returns the (simplified) Pig Latin version of the word."""
	vowel = {'a', 'e', 'i', 'o', 'u'}
	constants = {'b','c','d','f', 'g', 'h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'}
	# Student should complete function on the next lines.

	#gets the length of the word entered
	for words in vowel:
		if (word[0] == 'o'):
			con = True
			return (word + "way")
		else:
			if (word[1] != (words in vowel)):
				# for number in length:
					temp = word[0:1]
					word = word[2:]
					con = False
					return ( word + temp + "ay" )
			else:
				temp = word[0:1]
				word = word[1:]
				con2 = False
				return ( word + temp + "ay" )









###################################################
# Tests
# You should not change this code.

def test(word):
	"""Tests the pig_latin function."""
	print( "%s" % pig_latin(word) )

test("pig")
test("owl")
test("python")


###################################################
# Expected output
# You should look at the following comments and compare to printed output.
#
#
#owlway
#ythonpay
