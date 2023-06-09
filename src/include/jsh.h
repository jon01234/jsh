#ifndef JSHELL_JSH_H
#define JSHELL_JSH_H

#include <stdarg.h>
#include <stddef.h>

#define JSH_BUILTINCMD_COUNT 3

    
struct jshell 
{
    char *defaultprompt; // The default prompt on begining of each line
    char *line; // Inputed line from user
    size_t linelen; // The length of input line
    
    char **argv; // argv[0] is command so first argument is in argvalue[1]
    unsigned int argc; // argument count
    char cwd[256]; // current working directory

    char *builtincmd[JSH_BUILTINCMD_COUNT];
};

extern struct jshell jsh;

void jshell_getdir();
void jshell_main();
void jshell_error(char *err, int callperror);
void jshell_lex();

// TODO: implement!
// add functionality to pipe and chain commands
int jshell_parsecmd();
int jshell_fork();
int jshell_builtincmd(char *cmd);
void jshell_runbuiltincmd();
void jshell_runcmd();
void jshell_updatedir();
void jshell_clean();

#endif // !JSHELL_JSH_H
