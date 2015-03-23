CC_UNIX = clang++
CC_WIN = /usr/local/gcc-4.8.0-qt-4.8.4-for-mingw32/win32-gcc/bin/i586-mingw32-g++
LIBS_MAC = -framework Cocoa -framework Appkit -framework GLKit -framework OpenGl
LIBS_WIN = -lopengl32 -lglu32 -lglu32 -lgdi32
LIBS_GNU = -lX11 -lGL -lGLU
NAME= BackMaze

All:
	$(CC_UNIX) *.cpp -std=c++11  $(LIBS_GNU) -o $(NAME) -O3
mac:
	$(CC_UNIX) *.cpp -std=c++11 *.mm $(LIBS_MAC) -Info.plist -stdlib=libc++ -o $(NAME)  -O3 -fobjc-arc

windows:
	$(CC_WIN) *.cpp -std=c++11 $(LIBS_WIN) -O3 -o $(NAME).exe
clean:
	rm $(NAME)
	rm $(NAME).exe
