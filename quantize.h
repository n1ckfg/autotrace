/* Quantize a high color bitmap */

#include "color.h"

#ifndef QUANTIZE_H
#define QUANTIZE_H

#define PRECISION_R 	7
#define PRECISION_G 	7
#define PRECISION_B 	7

#define HIST_R_ELEMS 	(1<<PRECISION_R)
#define HIST_G_ELEMS 	(1<<PRECISION_G)
#define HIST_B_ELEMS 	(1<<PRECISION_B)

#define MR 		HIST_G_ELEMS*HIST_B_ELEMS
#define MG 		HIST_B_ELEMS

typedef unsigned long ColorFreq; 
typedef ColorFreq *Histogram; 
 
typedef struct { 
    int             desired_number_of_colors; /* Number of colors we will allow */ 
    int             actual_number_of_colors; /* Number of colors actually needed */ 
    color_type      cmap[256]; /* colormap created by quantization */
    ColorFreq       freq[256]; 
    Histogram       histogram; /* holds the histogram */ 
} QuantizeObj; 
 
void quantize(unsigned char *src,unsigned char *dest,int width, int height,long ncolors, color_type *bgColor, QuantizeObj **quantobj); 

#endif /* NOT QUANTIZE_H */

/* version 0.26 */
