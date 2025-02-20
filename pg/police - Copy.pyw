#Checking if pygame exists and importing it
try:
	import pygame
except ModuleNotFoundError:
	#Display an error message and exiting
	import os
	os.system("echo This Python file uses the Pygame module for visuals; "
		"it seems that it isn't installed so the file will not run."
		"&& timeout /t 10 && exit")
	exit()


def main():
	pygame.init()
	screen = pygame.display.set_mode((500, 500))
	#player coords
	player_x = 250
	player_y = 470
	#player dimensions
	player_w = 30
	player_h = 30
	#player change in movement
	player_c = 0
	#player direction (up/down/right/left)
	player_d = "d"
	#player speed by half pixels
	player_speed = 0.5
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
		screen.fill((0, 0, 0))
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				return
			if event.type == pygame.KEYDOWN:
				if event.key == pygame.K_RIGHT or event.key == pygame.K_d:
					player_c = player_speed
				if event.key == pygame.K_LEFT or event.key == pygame.K_a:
					player_c = -player_speed
				if event.key == pygame.K_UP or event.key == pygame.K_w:
					player_speed += 0.5
				if event.key == pygame.K_DOWN or event.key == pygame.K_s:
					if player_speed > 0.5:
						player_speed -= 0.5
				if event.key == pygame.K_LSHIFT or event.key == pygame.K_RSHIFT:
					if a:
						a = False
					elif not a:
						a = True
			if event.type == pygame.KEYUP:
				player_c = 0
		if player_d == "d":
			player_x += player_c
			if player_x >= 500 - player_w:
				player_d = "r"
			if player_x <= 0:
				player_d = "l"
		elif player_d == "u":
			player_x -= player_c
			if player_x >= 500 - player_w:
				player_d = "r"
			if player_x <= 0:
				player_d = "l"
		elif player_d == "r":
			player_y -= player_c
			if player_y >= 500 - player_h:
				player_d = "d"
			if player_y <= 0:
				player_d = "u"
		elif player_d == "l":
			player_y += player_c
			if player_y >= 500 - player_h:
				player_d = "d"
			if player_y <= 0:
				player_d = "u"
		if a:
			pygame.draw.rect(screen, (r, 0, b), (int(player_x), int(player_y), player_w, player_h))
		elif not a:
			pygame.draw.rect(screen, (230, 230, 230), (int(player_x), int(player_y), player_w, player_h))
		pygame.display.update()
		b += bc
		r += rc

if __name__ == '__main__':
	main()
