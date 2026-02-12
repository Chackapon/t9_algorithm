import sys

if (len(sys.argv) < 3):
    print("Usage:",sys.argv[0],"<words_file> <keys_file>")
    quit(1)

words_file_name = sys.argv[1]
keys_file_name = sys.argv[2]



keys_file = open(keys_file_name, "r")
keypad_characters = set()
for line in keys_file:
    if len(line) > 2:
        keypad_characters = keypad_characters.union( set( line.split()[1] ) )
keys_file.close()



words_file = open(words_file_name, "r")
result_file = open(words_file_name.split('.')[0] + "_filtered.txt", "w")
for line in words_file:
    if set(line.lower()) - keypad_characters == {'\n'}:
        result_file.write( line.lower() )



result_file.close()
words_file.close()
