try:
	import random
except ModuleNotFoundError:
	print("This Python file uses the standard Python module random for visuals; it seems that it isn't installed so the file will not run")
	exit()
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


pygame.init()
screen = pygame.display.set_mode((1120, 500), pygame.RESIZABLE)
pygame.display.set_caption("PyColor!")
icon = pygame.image.load("slider.png")
pygame.display.set_icon(icon)
r = pygame.image.load("Red.png")
rx = 0
rx_change = 0
g = pygame.image.load("Green.png")
gx = 0
gx_change = 0
b = pygame.image.load("Blue.png")
bx = 0
bx_change = 0
slider = pygame.image.load("slider.png")


def red():
	screen.blit(r, (rx, (screen.get_height() / 10) - 25))


def green():
	screen.blit(g, (gx, (screen.get_height() / 2) - 50))


def blue():
	screen.blit(b, (bx, (screen.get_height()) - (screen.get_height() / 10) - 75))


def sl():
	screen.blit(slider, (50, (screen.get_height() / 10)))
	screen.blit(slider, (50, (screen.get_height() / 2) - 25))
	screen.blit(slider, (50, ((screen.get_height()) - (screen.get_height() / 10) - 50)))


rs = False
gs = False
bs = False
running = True
while running:
	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			running = False
		if event.type == pygame.KEYDOWN:
			if event.key == pygame.K_x:
				xrx = random.randint(0, 1020)
				if rx < xrx:
					rx_change = 1
					rx += 1
			if event.key == pygame.K_r:
				if rs:
					rs = False
				else:
					rs = True
			if event.key == pygame.K_g:
				if gs:
					gs = False
				else:
					gs = True
			if event.key == pygame.K_b:
				if bs:
					bs = False
				else:
					bs = True
			if event.key == pygame.K_LEFT:
				if rs:
					rx_change = -1
				if gs:
					gx_change = -1
				if bs:
					bx_change = -1
			if event.key == pygame.K_RIGHT:
				if rs:
					rx_change = 1
				if gs:
					gx_change = 1
				if bs:
					bx_change = 1
			if event.key == pygame.K_ESCAPE:
				running = False
		if event.type == pygame.KEYUP:
			if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT or event.key == pygame.K_x:
				rx_change = 0
				gx_change = 0
				bx_change = 0
	screen.fill(((abs(rx)/4), (abs(gx)/4), (abs(bx)/4)))
	if rx >= 1020:
		rx = 1020
	elif rx <= 0:
		rx = 0
	if gx >= 1020:
		gx = 1020
	elif gx <= 0:
		gx = 0
	if bx >= 1020:
		bx = 1020
	elif bx <= 0:
		bx = 0
	rx += rx_change
	gx += gx_change
	bx += bx_change
	sl()
	red()
	green()
	blue()
	pygame.display.update()
