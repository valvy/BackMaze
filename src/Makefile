CXX=c++
NAME=Backmaze
CXXFLAGS= -g -Wall -std=c++11 -O3
LIBS=-framework Cocoa -framework Appkit -framework GLKit -framework OpenGl
LFLAGS= -o $(NAME) $(LIBS)
CXXOBJECTS=BackMaze.o MazeLoader.o Monster.o Tile.o Scene.o WinApp.o
OCCOBJECTS=MacApp.o

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o  $@ $^

%.o : %.mm
	$(CXX) $(CXXFLAGS) -fobjc-arc -c -o $@ $^

exe: $(CXXOBJECTS) $(OCCOBJECTS)
	$(CXX) $(CXXOBJECTS) $(OCCOBJECTS) $(LFLAGS)

clean:
	-rm -f $(CXXOBJECTS) $(OCCOBJECTS)
