#include <ncurses.h>
#include <vector>
#include <cstring>
#include <iostream>

#define COLS 80
#define ROWS 25

std::string prompt = "Enter command: ";
std::string currCommand = "";
std::string name = "";
std::string message = "";
std::string feedback = "";

void wallTitle(WINDOW* window, int &x, int &y) {
    std::string title = "Wall Contents";
    std::string underline = "-------------";
    for (char c : title) {
        mvaddch(y, x, c);
        x++;
    }
    x = 0;
    y++;
    for (char c : underline) {
        mvaddch(y, x, c);
        x++;
    }
    x = 0;
    y++;
}

void wallMessages(WINDOW* window, int &x, int &y, std::vector<std::string> &messages) {
    if (messages.size() == 0) {
        std::string empty = "[NO MESSAGES - WALL EMPTY]";
        for (char c : empty) {
            mvaddch(y, x, c);
            x++;
        }
    } else {
        for (std::string s : messages) {
            for (char c : s) {
                mvaddch(y, x, c);
                x++;
            }
            x = 0;
            y++;
        }
    }
    x = 0;
    y++;
}

void type(WINDOW* window, int &x, int &y, std::vector<std::string> &messages) { 
    if (prompt.find("Post") != std::string::npos) {
        message = currCommand;
        int length = 80 - message.size() - name.size() - 2;
        prompt = "Post [Max length " + std::to_string(length) + "]: ";
    }
    int i = 0;
    for (char c : prompt) {
        mvaddch(ROWS - 2, i, c);
        i++;
    }
    i = 0;
    for (char c : feedback) {
        mvaddch(ROWS - 1, i, c);
        i++;
    }
    int in_char = wgetch(window);
    const char* check = unctrl(in_char);
    if (in_char != ERR && check != 0 && strlen(check) == 1) {
        mvaddch(y, x, in_char);
        if (x < COLS) {
            currCommand += in_char;
            x++;
        } else if (y == ROWS - 2) {
            currCommand += in_char;
            x = 0;
            y++;
        }
    }
    if (in_char == KEY_BACKSPACE || in_char == KEY_DC || in_char == 127) {
        if (x > prompt.size()) {
            currCommand.pop_back();
            x--;
        } else if (y == ROWS - 1) {
            currCommand.pop_back();
            x = COLS - 1;
            y--;
        }
        mvaddch(y, x, ' ');
    }
    if (in_char == 10) {
        if (prompt == "Enter command: " && currCommand == "clear") {
            messages.clear();
            prompt = "Enter command: ";
            feedback = "Wall cleared.";
        } else if (prompt == "Enter command: " && currCommand == "post") {
            prompt = "Enter name: ";
            feedback = "";
        } else if (prompt == "Enter name: ") {
            name = currCommand;
            prompt = "Post [Max length " + std::to_string(80 - message.size()) + "]: ";
        } else if (prompt.find("Post") != std::string::npos) {
            prompt = "Enter command: ";
            if (message.size() <= 80) {
                messages.push_back(message);
                feedback = "Successfully tagged the wall.";
            } else {
                feedback = "Error: message is too long!";
            }
            message = "";
        } else if (currCommand == "kill" || currCommand == "quit") exit(0);
        currCommand = "";
        for (int j = 1; j < 3; j++) {
            for (int i = 0; i < COLS; i++) {
                mvaddch(ROWS - j, i, ' ');
            }
        }
        x = prompt.size();
        y = ROWS - 2;
        move(y, x);
    }
}

void clearScreen(WINDOW* window) {
    for (int y = 0; y < ROWS - 5; y++) {
        for (int x = 0; x < COLS; x++) {
            mvaddch(y, x, ' ');
        }
    }
}

int main(int argv, char** argc) {
    WINDOW* window = initscr();
    keypad(window, true);
    nodelay(window, true);
    curs_set(0);
    cbreak();
    noecho();
    clear();
    refresh();
    int x = 0, y = 0;
    int typeX = prompt.size(), typeY = ROWS - 2;
    std::vector<std::string> messages;
    move(y, x);
    while (1) {
        clearScreen(window);
        wallTitle(window, x, y);
        wallMessages(window, x, y, messages);
        type(window, typeX, typeY, messages);
        refresh();
        x = 0;
        y = 0;
    }
    return 0;
}

