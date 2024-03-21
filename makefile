# Compile labSix
labSix: labSix.cpp
	g++ labSix.cpp -o labSix

# Clean build files
clean:
	rm -f labSix *.o