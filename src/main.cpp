#include <fstream>
#include <iostream>
#include <ncurses.h>
#include <string>
#include <vector>

using namespace std;

vector<string> lines;

void loadFile(const string &filename) {
  ifstream file(filename);
  string line;
  while (getline(file, line)) {
    lines.push_back(line);
  }
  file.close();
}

void saveFile(const string &filename) {
  ofstream file(filename);
  for (const auto &line : lines) {
    file << line << endl;
  }
}

void runEditor() {
  initscr();
  noecho();
  keypad(stdscr, TRUE);

  int row = 0;

  while (true) {
    clear();
    int lineNum = 0;

    for (const auto &line : lines) {
      mvprintw(lineNum++, 0, "%s", line.c_str());
    }
    mvprintw(lineNum, 0,
             "[ESC] to exit | [enter] to new line | [Nackspace] to delete");

    refresh();

    int ch = getch();

    if (ch == 27)
      break;
    else if (ch == '\n') {
      lines.push_back("");
    } else if (ch == KEY_BACKSPACE || ch == 127) {
      if (!lines.empty() && !lines.back().empty()) {
        lines.back().pop_back();
      }
    } else {
      if (lines.empty())
        lines.push_back("");
      lines.back() += static_cast<char>(ch);
    }
  }
  endwin();
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " <filename>" << endl;
    return 1;
  }

  string filename = argv[1];
  loadFile(filename);
  runEditor();
  saveFile(filename);

  return 0;
}
