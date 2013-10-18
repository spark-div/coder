#include <iostream>
#include <iomanip>

#define MAXH 10
#define MAXW 10

int W = 5;
int H = 5;
const int WALL = -1;
const int BLANK = -2;

int px[MAXW * MAXH], py[MAXW * MAXH];
int len;
int grid[MAXH][MAXW];

bool lee(int ax, int ay, int bx, int by)
{
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  int d, x, y, k;
  bool stop;
  return false;
}

void spread_wave(int ax, int ay, int bx, int by)
{
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  int d, x, y, k;
  bool stop;
  d = 0;
  grid[ay][ax] = 0;
  do {
    stop = true;
    for ( y = 0; y < H; ++y )
      for ( x = 0; x < W; ++x )
        if ( grid[y][x] == d )
        {
          for ( k = 0; k < 4; ++k )
            if ( grid[y + dy[k]][x + dx[k]] == BLANK )
            {
              stop = false;
              grid[y + dy[k]][x + dx[k]] = d + 1;
            }
        }
    d++;
  } while ( !stop && grid[by][bx] == BLANK );
}

void print_grid()
{
    for (int y = 0; y < H; ++y )
    {
      for (int x = 0; x < W; ++x )
      {
         if (grid[y][x] == WALL )
            std::cout << "* ";
         else
         {
            std::cout.fill(0);
            std::cout.width(2);
            std::cout << grid[y][x] << " ";
         }
      }
      std::cout << std::endl;
    }
}

void input_file()
{
   std::cin >> W;
   H = W;
    for (int y = 0; y < H; ++y )
      for (int x = 0; x < W; ++x )
      {
         int val;
         std::cin >> val;
         if (val == 1)
           grid[y][x] = WALL;
      }
}

int main()
{
   input_file();
   print_grid();
   spread_wave(0,0,5,5);
   print_grid();
}