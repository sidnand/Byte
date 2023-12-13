#ifndef READER_H
#define READER_H

struct USER_FILE get_file(char *filepath);
const char *read_file(char *filepath);
const char *get_extension(const char *filename);

#endif