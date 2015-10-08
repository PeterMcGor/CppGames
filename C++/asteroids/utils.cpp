#include "utils.h"
#include <cmath>
using namespace std;
float limites(float& f, float max) {
    if (f>max) {
        f-= max;
    } else if ( f < 0) {
        f += max;
    }
    return f;
}

void rotar(float& x,float& y,float cx,float cy,float da) {
    float dx = x - cx;
    float dy = y - cy;
    float r = sqrt(dx*dx + dy*dy);
    float a = atan2(dy,dx);
    a-=da / 180 * M_PI;
    //Transformación a rectangulares
    x = cx + r * cos(a);
    y= cy + r * sin(a);

 }
