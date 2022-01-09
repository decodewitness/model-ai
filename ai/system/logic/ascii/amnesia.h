// AMNESIA.CPP - DISPLAYS A ROTATING DOUGHNUT.

#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <string.h>

/* (C) INFORMATION ABOUT THE FOLLOWING FUNCTION: 06:23PM (09-11-2021):
 *	-----
 *	The original sample in my original code mentioning 'Andy Sloane' belongs to
 *	this single function (originally) which was a fragment of code borrowed,
 *	for our original project "model-ai" & then readapted the code and also remade it:
 *
 *     (&p.s. we haven't really checked if it still is mathematical geometrically significant)
 *
 *	"rotate_donut_3D(void);
 * 	rotate_donut_3D(){ was the function in the original code originally coded by "Andy Sloane"; }
 *	void rotate_donut_3D(void);
 *	original website for this code fragment: ("https://www.a1k0n.net/2011/07/20/donut-math.html");
 */

int amnesia(int constr=55) {   // we have given our own representation to this code.
  int k;
  char b[1760];
  float A=0,B=0,i,j,z[1760];

  for(int ij=0;ij<constr;ij++){
    memset(b,32,1760);
    memset(z,0,7040);
  
    for(j=0;6.28>j;j+=0.07)
      for(i=0;6.28>i;i+=0.02){
        float c=sin(i),d=cos(j),e=sin(A),f=sin(j),g=cos(A),h=d+2,D=1/(c*h*e+f*g+5),l=cos(i),m=cos(B),n=sin(B),t=c*h*g-f*e;int x=40+30*D*(l*h*m-t*n),y=12+15*D*(l*h*n+t*m),o=x+80*y,N=8*((f*e-c*d*g)*m-c*d*e-f*g-l*d*n);if(22>y&&y>0&&x>0&&80>x&&D>z[o]){z[o]=D;;;b[o]=".,+~:;+1*248"[N>0?N:0];
      }
    }
    for(k=0;1761>k;k++)
    putchar(k%80?b[k]:10);A+=0.04;B+=0.02;
  }

return 1;
}

