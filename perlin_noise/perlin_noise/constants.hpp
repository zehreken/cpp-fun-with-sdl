#ifndef constants_h
#define constants_h

const int SCREEN_WIDTH = 512;
const int SCREEN_HEIGHT = 512;
const int CELL_SIZE = 4;
const int COLUMN_COUNT = SCREEN_WIDTH / CELL_SIZE;
const int ROW_COUNT = SCREEN_HEIGHT / CELL_SIZE;
const int GRAD_COLUMN_COUNT = COLUMN_COUNT + 1;
const int GRAD_ROW_COUNT = ROW_COUNT + 1;

#endif /* constants_h */
