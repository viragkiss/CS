# Obstruction Game
# By Virag Kiss
# Net ID: vkk243


#------------------SETUP------------------------#

# import methods
import random
import os

# declare global constants - board dimensions

print("What are your preferred dimensions?")
NUM_ROWS = ""
NUM_COLUMNS = ""

# for convenience, number of rows and columns must be
# within the given boundary

while True:
	NUM_ROWS = int(input("Enter the number of rows: "))
	NUM_COLUMNS = int(input("Enter the number of columns: "))

	if NUM_ROWS > 9 or NUM_ROWS < 3:
		print("Invalid input: Valid inputs are [3 - 9]")
		continue
	if NUM_COLUMNS > 9 or NUM_COLUMNS < 3:
		print("Invalid input: Valid inputs are [3 - 9]")
		continue
	break

# global constants - number of players and checkers

NUM_PLAYERS = 2
X_PLAYER = 'X '
O_PLAYER = 'O '

# initialize board

# the board list contains only empty spaces to make it
# easier to perform commands on its individual elements
# eg. validate for cell already taken

board = []

for r in range(NUM_ROWS):
	row_numbers = []
	for c in range(NUM_COLUMNS):
		row_numbers.append(' ')
	board.append(row_numbers)


# use the spaces_left variable to check if
# further inputs are possible or the game has ended

spaces_left = NUM_ROWS * NUM_COLUMNS

# use the list of letters to print the board header
# within range of number of columns
# convert list to a string for nicer print
# use this list to map user input coordinates(str) to board coordinates(int)

letters_all = []
for i in range(65, 91):
    letters_all.append(chr(i))
letters = (letters_all[:NUM_COLUMNS])
letter_coordinates = '   '.join(letters)


# clear the screen to start the game
os.system('clear')




#--------------------GAME PHASE--------------------------#

# select first random player

turn = random.randint(0, NUM_PLAYERS - 1)

if turn == 1:
	next_player = X_PLAYER
else:
	next_player = O_PLAYER

# assign empty value to coordinates variable outside
# loop so that it can be reused
coordinates = ""


# main phase inside while loop repeating until no more valid
# input is possible to place checkers
# here checking for the end of the game

while spaces_left != 0:
	
	# print the empty board at first turn
	# print an updated board at subsequent turns

	print('  ', letter_coordinates)
	for r in range(NUM_ROWS):
		print(' ', '+---' * NUM_COLUMNS, '+', sep='')
		print(r, '| ', sep='', end='')
		for c in range(NUM_COLUMNS):
			if board[r][c] == X_PLAYER:
				print(board[r][c], sep='', end='| ')
			elif board[r][c] == O_PLAYER:
				print(board[r][c], sep='', end='| ')
			elif board[r][c] == '# ':
				print(board[r][c], sep='', end='| ')
			else:
				print('  ', sep='', end='| ')
		print()
	print(' ', '+---' * NUM_COLUMNS, '+', sep='')


	# assign the next player, X or O depending on who started

	if next_player == X_PLAYER:
		next_player = O_PLAYER
	else:
		next_player = X_PLAYER


	# check the validity of user input
	# use format print f to create dynamic print

	while True:
		
		coordinates = input('Enter coordinates for your move: ')

		# if it is the correct length of 2 characters
		if len(coordinates) != 2:
			print(f"Invalid input: Valid inputs are [A-{chr(NUM_COLUMNS+64)}][0-{NUM_ROWS -1}]")
			continue

		# if it is the correct format: letter followed by number
		if not (coordinates[0].isalpha()) or not (coordinates[1].isdigit()):
			print(f"Invalid input: Valid inputs are [A-{chr(NUM_COLUMNS+64)}][0-{NUM_ROWS -1}]")
			continue

		# if the letter and number are within range of the board dimensions
		if (ord(coordinates[0]) - 65 >= NUM_COLUMNS) or (int(coordinates[1]) >= NUM_ROWS):
			print(f"Invalid input: Valid inputs are [A-{chr(NUM_COLUMNS+64)}][0-{NUM_ROWS -1}]")
			continue

		# if the letter is lower case - in this program only upper case is allowed
		if 97 <= ord(coordinates[0]) <= 122:
			print(f"Invalid input: Valid inputs are [A-{chr(NUM_COLUMNS+64)}][0-{NUM_ROWS -1}]")
			continue

		# map the letter from input to the corresponding
		# int coordinate in column dimensions using 'letters' list

		column = letters.index(coordinates[0])
		r = int(coordinates[1])

		# check if the coordinates entered belong to an occupied cell
		if board[r][column] != ' ':
			print('Invalid input: Cell already taken. Pick an empty cell.')
			continue

		break

	# in board list, replace ' ' with X or O depending on which player is playing
	# decrement number of spaces left for each X or O

	board[r][column] = next_player
	spaces_left -= 1

	# replace surrounding blank spaces with #
	# as long as the character to be replaced is within range
	# decrement number of spaces left for each #

	for x in [-1, 0, 1]:
		for y in [-1, 0, 1]:
			if not (x == 0 and y == 0):
				X = r + x
				Y = column + y
				if (0 <= X < NUM_ROWS) and (0 <= Y < NUM_COLUMNS):
					if board[X][Y] == ' ':
						board[X][Y] = '# '
						spaces_left -= 1

	# clear the screen for the next round
	os.system('clear')


#-------------------END OF GAME----------------------#

# print the final board as the while loop only runs
# as long as the spaces_left variable is not 0

print('  ', letter_coordinates)
for r in range(NUM_ROWS):
	print(' ', '+---' * NUM_COLUMNS, '+', sep='')
	print(r, '| ', sep='', end='')
	for c in range(NUM_COLUMNS):
		if board[r][c] == X_PLAYER:
			print(board[r][c], sep='', end='| ')
		elif board[r][c] == O_PLAYER:
			print(board[r][c], sep='', end='| ')
		elif board[r][c] == '# ':
			print(board[r][c], sep='', end='| ')
		else:
			print('  ', sep='', end='| ')
	print()
print(' ', '+---' * NUM_COLUMNS, '+', sep='')
print()

print('Game Over')
print()

# the last player who managed to place their checker wins
# check for the last player here

if next_player == X_PLAYER:
	print('X wins!')
else:
	print('O wins!')

print()
