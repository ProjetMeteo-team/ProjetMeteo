CC=gcc
EXECUTABLE_NAME=Meteo

# Optional (use root if empty)
BUILD_FOLDER=

# Release
release : all clean
run_release : release run

# Compilation
main.o :
	@$(CC) -c main.c -o $(BUILD_FOLDER)main.o

tri.o :
	@$(CC) -c tri.c -o $(BUILD_FOLDER)tri.o

# Everything at once
all : main.o tri.o
	@$(CC) $(BUILD_FOLDER)main.o $(BUILD_FOLDER)tri.o -o $(EXECUTABLE_NAME)

# Cleaner
clean :
	@rm -f $(BUILD_FOLDER)main.o $(BUILD_FOLDER)tri.o

# Runners
run : all
	@echo "Running $(EXECUTABLE_NAME)"
	@./$(EXECUTABLE_NAME)
