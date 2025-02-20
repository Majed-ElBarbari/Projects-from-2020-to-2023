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
	mr = True
	while mr:
		pygame.init()
		pygame.font.get_fonts()
		w = pygame.display.set_mode((800, 600))
		pygame.display.set_caption("Pong")
		b0x = 390
		b0y = 290
		p1y = 250
		p2y = 250
		p1yc = 0
		p2yc = 0
		p1p = 0
		p2p = 0
		sf = pygame.font.Font("freesansbold.ttf", 22)
		b0xc = 0.3
		b0yc = 0.3
		ps = 0.3
		r = True
		st = True
		while r:
			w.fill((0, 0, 0))
			if st:
				pygame.time.wait(1000)
				st = False
			for event in pygame.event.get():
				if event.type == pygame.QUIT:
					pygame.quit()
					return
				if event.type == pygame.KEYDOWN:
					if event.key == pygame.K_w:
						p1yc = -ps
					if event.key == pygame.K_s:
						p1yc = ps
					if event.key == pygame.K_UP:
						p2yc = -ps
					if event.key == pygame.K_DOWN:
						p2yc = ps
				if event.type == pygame.KEYUP:
					p1yc = 0
					p2yc = 0
			if sn is not None:
				if p1p == sn or p2p == sn:
					pygame.quit()
					return
			if b0y <= 0:
				b0yc = abs(b0yc)
			if b0y >= 580:
				b0yc = -abs(b0yc)
			if p1y <= 0:
				p1y = 0
			if p1y >= 500:
				p1y = 500
			if p2y <= 0:
				p2y = 0
			if p2y >= 500:
				p2y = 500
			if b0x <= -20:
				p2p += 1
				p1y = 250
				p2y = 250
				b0x = 390
				b0y = 290
				b0xc = abs(b0yc + 0.1)
				pygame.time.wait(1000)
			if b0x >= 820:
				p1p += 1
				p1y = 250
				p2y = 250
				b0x = 390
				b0y = 290
				b0xc = abs(b0yc + 0.1)
				pygame.time.wait(1000)
			if 730 >= b0x >= 710:
				if p2y + 100 >= b0y >= p2y:
					b0xc = -abs(b0xc)
			if 50 <= b0x <= 70:
				if p1y + 100 >= b0y >= p1y:
					b0xc = abs(b0xc)
			b0x += b0xc
			b0y += b0yc
			p1y += p1yc
			p2y += p2yc
			p1st = sf.render(str(p1p), True, (255, 255, 255, 100))
			w.blit(p1st, (350, 10))
			p1st = sf.render(str(p2p), True, (255, 255, 255, 100))
			w.blit(p1st, (450, 10))
			pygame.draw.rect(w, (255, 255, 255), (50, int(p1y), 20, 100))
			pygame.draw.rect(w, (255, 255, 255), (730, int(p2y), 20, 100))
			pygame.draw.rect(w, (255, 255, 255), (int(b0x), int(b0y), 20, 20))
			pygame.display.update()


a = True
while a:
	print("Play Pong?")
	start = input()
	if start == "1":
		sn = None
		sr = True
		sl = None
		while sr:
			print("Score Limit?")
			sc = input()
			sl = None
			if sc == "1":
				sr = False
				sl = True
			elif sc == "0":
				sr = False
				sl = False
			else:
				print("Input 0(reject) or 1(accept)!")
		while sl:
			print("Score Limit(classic pong is 7 points):")
			sc = input()
			sn = None
			try:
				sn = 0 + int(sc)
				sl = False
			except ValueError:
				print("Input number!")
		if __name__ == '__main__':
			main()
	elif start == "0":
		a = False
	else:
		print("Input 1 (to accept) or 0 (to reject)")
