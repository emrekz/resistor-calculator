all :
		gcc `pkg-config --cflags gtk4` -o run main.c calculate.c image.c `pkg-config --libs gtk4` -mwindows
