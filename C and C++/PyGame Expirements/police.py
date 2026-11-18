try:
	try:
		import os
		os.environ['PYGAME_HIDE_SUPPORT_PROMPT'] = '' #To remove pygame msg
	except ModuleNotFoundError:
		pass
	import pygame
except ModuleNotFoundError:
	input("This Python file uses the Pygame module for visuals;"
              "it seems that it isn't installed so the file will not run."
              "/nPress any button to exit...")
	exit()


def main():
	pygame.init()
	win = pygame.display.set_mode((500, 500))
	rect_x = 250
	rect_y = 470
	rect_w = 30
	rect_h = 30
	rect_c = 0
	rect_d = "d"
	b = 0
	bc = 1
	r = 0
	rc = 1
	f = 1.5
	m = 0
	a = True
	while 1:
		if m == 0:
			if b != 255:
				bc = abs(f)
				rc = 0
				m = 1
		elif m == 1:
			if b >= 255:
				bc = -abs(f)
				rc = 0
			if b <= 0:
				bc = 0
				m = 2
		elif m == 2:
			if r != 255:
				rc = abs(f)
				bc = 0
				m = 3
		elif m == 3:
			if r >= 255:
				rc = -abs(f)
				bc = 0
			if r <= 0:
				rc = 0
				m = 0
		win.fill((0, 0, 0))
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				return
			if event.type == pygame.KEYDOWN:
				if event.key == pygame.K_RIGHT:
					rect_c = 0.5
				if event.key == pygame.K_LEFT:
					rect_c = -0.5
				if event.key == pygame.K_SPACE:
					if a:
						a = False
					elif not a:
						a = True
			if event.type == pygame.KEYUP:
				rect_c = 0
		if rect_d == "d":
			rect_x += rect_c
			if rect_x >= 470:
				rect_d = "r"
			if rect_x <= 0:
				rect_d = "l"
		elif rect_d == "u":
			rect_x -= rect_c
			if rect_x >= 470:
				rect_d = "r"
			if rect_x <= 0:
				rect_d = "l"
		elif rect_d == "r":
			rect_y -= rect_c
			if rect_y >= 470:
				rect_d = "d"
			if rect_y <= 0:
				rect_d = "u"
		elif rect_d == "l":
			rect_y += rect_c
			if rect_y >= 470:
				rect_d = "d"
			if rect_y <= 0:
				rect_d = "u"
		if a:
			pygame.draw.rect(win, (r, 0, b), (int(rect_x), int(rect_y), rect_w, rect_h))
		elif not a:
			pygame.draw.rect(win, (230, 230, 230), (int(rect_x), int(rect_y), rect_w, rect_h))
		pygame.display.update()
		b += bc
		r += rc


if __name__ == '__main__':
	main()
