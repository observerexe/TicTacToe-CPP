#pragma once
void printField(const char field[3][3]);
void fillField(char field[3][3]);
bool checkWin(const char field[3][3], const char player);
bool checkDraw(const char field[3][3]);
void playerInput(int& row, int& col);
void playerProcessing(char field[3][3], char player);
void botProcessing(char field[3][3], char player);