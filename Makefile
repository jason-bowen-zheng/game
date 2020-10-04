all: walk.c gldemo.c
	@make walk
	@make gldemo

walk: walk.c
	@gcc walk.c -o walk -lncurses

gldemo: gldemo.c
	@gcc gldemo.c -o gldemo -lGLEW -lGL -lGLU -lglut -lm -lX11

clean:
	@-rm walk gldemo
