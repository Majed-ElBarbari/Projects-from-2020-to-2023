try:
	try:
		import os
		os.environ['PYGAME_HIDE_SUPPORT_PROMPT'] = ''
	except ModuleNotFoundError:
		pass
	import pygame
except ModuleNotFoundError:
	print("This Python file uses the Pygame module for visuals; it seems that it isn't installed so the file will not run")
	exit()

def main():
	pass

if __name__ == '__main__':
	main()
