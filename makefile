# Compile labSix
labSix: labSix.c
	gcc labSix.c -o labSix

# Clean build files
clean:
	rm -f labSix *.o