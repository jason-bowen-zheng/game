all: walk.c gldemo.c
	@make walk
	@make gldemo

walk: walk.c
	@gcc walk.c -o walk -O3 -lncurses

gldemo: gldemo.c
	@gcc gldemo.c -o gldemo -O3 -lGLEW -lGL -lGLU -lglut -lm -lX11

clean:
	@-rm walk gldemo
