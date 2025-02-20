try:
	try:
		import os
		os.environ['PYGAME_HIDE_SUPPORT_PROMPT'] = ''
	except ModuleNotFoundError:
		pass
	import pygame
except ModuleNotFoundError:
	print("This Python file uses the Pygame module for visuals; it seems that it isn't installed so the file will run but with no graghics")


morse = {
	" ":     "       ",
	"A":         "· −",
	"B":     "− · · ·",
	"C":     "− · − ·",
	"D":       "− · ·",
	"E":           "·",
	"F":     "· · − ·",
	"G":       "− − ·",
	"H":     "· · · ·",
	"I":         "· ·",
	"J":         "· −",
	"K":       "− · −",
	"L":     "· − · ·",
	"M":         "− −",
	"N":         "− ·",
	"O":       "− − −",
	"P":     "· − − ·",
	"Q":     "− − · −",
	"R":       "· − ·",
	"S":       "· · ·",
	"T":           "−",
	"U":       "· · −",
	"V":     "· · · −",
	"W":       "· − −",
	"X":     "− · · −",
	"Y":     "− · − −",
	"Z":     "− − · ·",
	"a":         "· −",
	"b":     "− · · ·",
	"c":     "− · − ·",
	"d":       "− · ·",
	"e":           "·",
	"f":     "· · − ·",
	"g":       "− − ·",
	"h":     "· · · ·",
	"i":         "· ·",
	"j":         "· −",
	"k":       "− · −",
	"l":     "· − · ·",
	"m":         "− −",
	"n":         "− ·",
	"o":       "− − −",
	"p":     "· − − ·",
	"q":     "− − · −",
	"r":       "· − ·",
	"s":       "· · ·",
	"t":           "−",
	"u":       "· · −",
	"v":     "· · · −",
	"w":       "· − −",
	"x":     "− · · −",
	"y":     "− · − −",
	"z":     "− − · ·",
	"0":   "− − − − −",
	"1":   "· − − − −",
	"2":   "· · − − −",
	"3":   "· · · − −",
	"4":   "· · · · −",
	"5":   "· · · · ·",
	"6":   "− · · · ·",
	"7":   "− − · · ·",
	"8":   "− − − · ·",
	"9":   "− − − − ·",
	".": "· − · − · −",
	",": "− − · · − −",
	"?": "· · − − · ·",
	"'": "· − − − − ·",
	"!": "− · − · − −",
	"/":   "− · · − ·",
	"(":   "− · − − ·",
	")": "− · − − · −",
	"&":     "· − · ·",
	":": "− − − · · ·",
	";": "− · − · − ·",
	"=":   "− · · · −"}


def convert1(text):
	code1 = ""
	for char in text:
		if char in "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.,?'!/()&:;= ":
			code1 += morse[char]
			if char == " ":
				code1 += ""
			else:
				code1 += "   "
	return code1


def convert2(morse_code):
	code2 = ""
	for char2 in morse_code:
		if char2 == "−":
			code2 += "111"
		elif char2 == "·":
			code2 += "1"
		elif char2 == " ":
			code2 += "0"
	return code2


x = []
y = []


class Codes:
	def __init__(self, c0):
		self.c0 = c0
		self.c1 = convert1(self.c0)
		self.c2 = convert2(self.c1)

	def o0(self):
		print(self.c1)
		print(self.c2)

	def o1(self):
		print("You inputted: " + self.c0 + " In morse it is: " + self.c1 + " The timing is: " + self.c2)


class Visual:
	def __init__(self, v):
		self.v = v
		self.v += "z"
		self.screen = None
		try:
			self.win()
		except ModuleNotFoundError:
			pass

	def win(self):
		pygame.init()
		self.screen = pygame.display.set_mode((201, 201))
		pygame.display.set_caption("Morse")
		icon = pygame.image.load("slider.png")
		pygame.display.set_icon(icon)
		self.scan()

	def scan(self):
		for char3 in self.v:
			if char3 == "1":
				self.screen.fill((255, 255, 255))
				pygame.display.update()
				pygame.time.delay(250)
			elif char3 == "0":
				self.screen.fill((0, 0, 0))
				pygame.display.update()
				pygame.time.delay(250)
			elif char3 == "z":
				pygame.quit()


def q0():
	print("Morse?")
	start = input()
	if start == "0":
		for i in x:
			i.o1()
		return False
	elif start == "1":
		return True
	else:
		print("Input 1 or 0!")
		return q0()


def q1():
	global x
	x.append(Codes(input()))
	x[-1].o0()
	return x[-1].c2


def main():
	while True:
		mr = q0()
		if mr:
			y.append(Visual(q1()))
		elif not mr:
			break


if __name__ == '__main__':
	main()
