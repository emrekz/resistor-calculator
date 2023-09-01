all :
		gcc `pkg-config --cflags gtk4` -o run ./src/main.c ./src/calculate.c ./src/image.c `pkg-config --libs gtk4` -mwindows
