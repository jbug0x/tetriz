#pragma once

constexpr int COLUMNS = 10;
constexpr int ROWS = 20;
constexpr int CELL_SIZE = 50;

constexpr int BOARD_WIDTH = COLUMNS * CELL_SIZE; // 500
constexpr int SIDE_PANEL_WIDTH = 300;

constexpr int SCREEN_WIDTH = BOARD_WIDTH + SIDE_PANEL_WIDTH; // 800
constexpr int SCREEN_HEIGHT = ROWS * CELL_SIZE;              // 1000