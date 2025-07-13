#include "shell.h"
#include "keyboard.h"
#include "../drivers/frame_buffer.h"

#define SHELL_INPUT_LEN 128

static char input_buf[SHELL_INPUT_LEN];
static int input_pos = 0;

void shell_print_prompt() {
    fb_write_str("\n> ");
}

void shell_clear() {
    fb_clear();
    shell_print_prompt();
}

void shell_help() {
    fb_write_str("\nShell commands:");
    fb_write_str("\nhelp  - Show this help");
    fb_write_str("\nclear - Clear the screen");
    fb_write_str("\necho [msg] - Print a message\n");
}

void shell_echo(const char* msg) {
    fb_write_str("\n");
    fb_write_str(msg);
}

void shell_handle_cmd(const char* cmd) {
    if (!cmd[0]) return;
    if (input_pos == 0) return;
    if (!strncmp(cmd, "help", 4)) shell_help();
    else if (!strncmp(cmd, "clear", 5)) shell_clear();
    else if (!strncmp(cmd, "echo", 4)) shell_echo(cmd+5);
    else fb_write_str("\nUnknown command.");
}

void shell_start() {
    fb_write_str("Simple OS Shell. Type 'help'.\n");
    shell_print_prompt();
    input_pos = 0;
    while (1) {
        char c = keyboard_readchar();
        if (c) {
            if (c == '\n' || c == '\r') {
                input_buf[input_pos] = 0;
                shell_handle_cmd(input_buf);
                input_pos = 0;
                shell_print_prompt();
            } else if (c == '\b') {
                if (input_pos > 0) {
                    input_pos--;
                    fb_write('\b', 0);
                }
            } else if (input_pos < SHELL_INPUT_LEN-1) {
                input_buf[input_pos++] = c;
            }
        }
    }
}
