#ifndef SHELL_H
#define SHELL_H

/***** MACROS *****/
#define PRINT(c) (write(STDERR_FILENO, c, _strlen(c)))
#define BUFSIZE 10240
#define DELIMITER " \t\r\n\a"

/*** STANDARD LIBRARIES ***/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

/******** STRING HANDLER FUNCTIONS **********/

char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void array_rev(char *arr, int len);
int intlen(int num);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);

/*********** MEMORY HANDLERS ***********/

void free_env(char **env);
void *Array_fill(void *i, int cd, unsigned int length);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_memory(char **input, char *line);

/****** MISCELLANEOUS AND INPUT FUNCTIONS *******/

char *_getline();
char *space(char *str);
char *enter(char *string);
void handler(char *buff);
void prompt(void);
unsigned int check_delim(char c, const char *str);
char *_2strtok(char *str, const char *delimeter);
int history(char *input);
char **separator(char *input);

/****** FILE ARGUMENT HANDLER FUNCTIONS ******/

void read_file(char *file, char **argv);
void treat_file(char *arr, int number, FILE *fn, char **argv);
void exit_bulp_for_file(char **cmd, char *line, FILE *fn);

/****** PARSED ARGUMENT HANDLER FUNCTIONS *****/

char **cmd_parse(char *input);
int handle_builtin(char **cmd, int er);
int find_cmd(char **cmd, char *input, int q, char **argv);
void signal_to_handle(int sig);

/******* ERROR HANDLERS ******/

void print_error(char *input, int counter, char **argv);
void perror(char **argv, int c, char **cmd);
void file_error(char **argv, int c);

/****** ENVIRONMENT HANDLERS ******/

extern char **environ;
void create_environ(char **environ);
void free_environ(char **envi);

/****** PRINTING FUNCTIONS *****/

void print_number(unsigned int n);
void print_number_int(int n);
int print_echo(char **cmd);

/******* PATH FINDER *******/

int path_cmd(char **cmd);
char *make(char *token, char *number);
char *_find_env(char *got);

/******* ASSIST HANDLERS *******/

void assist_env(void);
void assist_setenv(void);
void assist_unsetenv(void);
void assist_hist(void);
void assist_all(void);
void assist_alias(void);
void assist_cd(void);
void assist_exit(void);
void assist_inuse(void);
int present_assist(char **cmd, __attribute__((unused))int st);

/****** BUILTIN COMMAND HANDLERS AND EXECUTE ******/

int find_builtin(char **cmd);
int handle_builtin(char **cmd, int st);
void exit_bulp(char **cmd, char *input, char **argv, int c, int stat);
int change_directory(char **cmd, __attribute__((unused))int st);
int display_env(__attribute__((unused)) char **cmd,
	    __attribute__((unused)) int st);
int echo_bulp(char **cmd, int st);
int his_display(__attribute__((unused))char **c,
		__attribute__((unused)) int st);

/****** BUILT-IN COMMANDS STRUCT *****/

/**
 * struct _builtin - Defines a struct that conatins built-in commands
 * with their respective implementation functions
 * @command: - Built-in command
 * @function: - Pointer to custom functions that have
 * similar functionalities as the built-in commands
 */
typedef struct _builtin
{
	char *command;
	int (*function)(char **line, int st);
} builtin;

#endif

