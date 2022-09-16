#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *readfile(char *file_name) {
  char *file_contents;
  long input_file_size;
  FILE *input_file = fopen(file_name, "rb");
  if (!input_file) {
    puts("problem reading file");
    exit(1);
  } else {
    fseek(input_file, 0, SEEK_END);
    input_file_size = ftell(input_file);
    rewind(input_file);
    file_contents = malloc(input_file_size * (sizeof(char)));
    fread(file_contents, sizeof(char), input_file_size, input_file);
    fclose(input_file);
    return (file_contents);
  }
}

char **get_frames(char *file_name) {
  char *framebuf = readfile(file_name);
  char *token;
  char **frames;
  char *file_contents;
  long input_file_size;
  FILE *input_file = fopen(file_name, "rb");
  if (!input_file) {
    puts("problem reading file");
    exit(1);
  } else {
    fseek(input_file, 0, SEEK_END);
    input_file_size = ftell(input_file);
    frames = (char **)malloc(input_file_size * (sizeof(char)));
    fclose(input_file);
  }
  token = strtok(framebuf, "\%");

  int i = 0;
  do {
    frames[i] = token;
    i++;
  } while ((token = strtok(NULL, "\%")));

  frames[i] = "\0";
  return (frames);
}

void clear_screen() { puts("\e[2J\e[H"); }

int main(int argc, char **argv) {

  char *filename;

  if (argc == 2) {
    filename = argv[1];
  } else {
    puts("expected filename: ansimate [FILE]");
    exit(1);
  }

  char **frames = get_frames(filename);

  while (1) {
    int i = 0;
    char *frame = frames[i];
    clear_screen();

    while (strcmp(frame, "\0") != 0) {
      clear_screen();
      printf("%s", frame);
      sleep(1);
      i++;
      frame = frames[i];
    }
  }
}
