#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long byte_count(char *fname) {
  long count = 0;

  FILE *fp = fopen(fname, "r");
  if (!fp) {
    perror("File opening failed");
    exit(1);
  }

  int c;
  while ((c = getc(fp)) != EOF)
    count++;

  fclose(fp);

  return count;
}

long line_count(char *fname) {
  long count = 0;

  FILE *fp = fopen(fname, "r");
  if (!fp) {
    perror("File opening failed");
    exit(1);
  }

  int c;
  while ((c = getc(fp)) != EOF) {
    if (c == '\n')
      count++;
  }

  fclose(fp);

  return count;
}

long word_count(char *fname) {
  long count = 0;

  FILE *fp = fopen(fname, "r");
  if (!fp) {
    perror("File opening failed.");
    exit(1);
  }

  int c;
  bool previous_char_whitespace = false;
  while ((c = getc(fp)) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
      if (!previous_char_whitespace) {
        count++;
      }
      previous_char_whitespace = true;
    } else {
      previous_char_whitespace = false;
    }
  }

  return count;
}

long char_count(char *fname) {
  long count = 0;

  FILE *fp = fopen(fname, "r");
  if (!fp) {
    perror("File opening failed.");
    exit(1);
  }

  int c;
  while ((c = getc(fp)) != EOF) {
    count++;
  }

  fclose(fp);

  return count;
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("Expected an option. Display help here.\n");
    return 1;
  } else if (argc == 3) {
    char *opt_1 = argv[1];
    if (strcmp(opt_1, "-c") == 0) {
      char *fname = argv[2];
      long count = byte_count(fname);
      printf("%ld %s\n", count, fname);
    } else if (strcmp(opt_1, "-l") == 0) {
      char *fname = argv[2];
      long count = line_count(fname);
      printf("%ld %s\n", count, fname);
    } else if (strcmp(opt_1, "-w") == 0) {
      char *fname = argv[2];
      long count = word_count(fname);
      printf("%ld %s\n", count, fname);
    } else if (strcmp(opt_1, "-m") == 0) {
      char *fname = argv[2];
      long count = char_count(fname);
      printf("%ld %s\n", count, fname);
    } else {
      printf("error, invalid option.\n");
      return 1;
    }
  } else if (argc == 2) {
    char *fname = argv[1];
    long wordCount = word_count(fname);
    long lineCount = line_count(fname);
    long byteCount = byte_count(fname);
    printf("%ld  %ld   %ld  %s\n", lineCount, wordCount, byteCount, fname);
  } else {
  }
  return 0;
}
