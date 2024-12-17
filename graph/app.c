#include "sim.h"

#include <stdio.h>
#include <stdlib.h>

#define ROWS (SIM_X_SIZE)
#define COLS (SIM_Y_SIZE)
#define STEPS 10
#define PNTS 10
#define CALCS 5

int is_good_pnt(int x, int y) {
  return !(x <= 0 || x >= SIM_X_SIZE || y <= 0 || y >= SIM_Y_SIZE);
}

void drawLine(int x, int y, int x_len, int y_len, int v_abs) {
  for (int step = 0; step < STEPS; step++) {
    int xt = x + x_len * step / STEPS, yt = y + y_len * step / STEPS;
    if (is_good_pnt(xt, yt))
      simPutPixel(xt, yt, 0xFF0000FF + (v_abs << 16));
  }
}

int getAbsVelocity(int v1, int v2) {
  if (v1 < 0)
    v1 = -v1;
  if (v2 < 0)
    v2 = -v2;
  return (v1 + v2) & 0xFF;
}

void app() {
  const int dec=100;
  const int tmsc=10000;
  const int a = SIM_Y_SIZE/2, b=1, g=SIM_X_SIZE/2, d=1;
  int xs[PNTS] = {};
  int ys[PNTS] = {};
  for (int i=0; 1; i++) {
    for (int p=0; p<PNTS; p++) {
      int x=xs[p], y=ys[p];
      if (!is_good_pnt(x/dec, y/dec)) {
        x = ((simRand() % SIM_X_SIZE)/3 + SIM_X_SIZE/2)*dec;
        y = ((simRand() % SIM_Y_SIZE)/3 + SIM_Y_SIZE/2)*dec;
        x = 40000;
        y = 30000;
      }
      int v_x = a*x - b*x*y/dec;
      v_x /= tmsc;
      int v_y = -g*y + d*x*y/dec;
      v_y /= tmsc;
      if (i%CALCS == 0) {
        drawLine(x/dec, y/dec, CALCS*v_x/dec, CALCS*v_y/dec, getAbsVelocity(v_x, v_y));
        simFlush();
      }
      x += v_x;
      y += v_y;
      printf("%d %d\n", x,y);
      xs[p] = x;
      ys[p] = y;
    }
  }
}

