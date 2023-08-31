#include "header.h"

const char *imageText_l[] = {"./images/l_black.png", "./images/l_brown.png", "./images/l_red.png", "./images/l_orange.png", "./images/l_yellow.png", \
                           "./images/l_green.png", "./images/l_blue.png", "./images/l_purple.png", "./images/l_grey.png", "./images/l_white.png", \
                           "./images/l_gold.png", "./images/l_silver.png", NULL};

const char *imageText_l_2[] = {"./images/l_brown.png", "./images/l_red.png", "./images/l_orange.png", "./images/l_yellow.png", \
                           "./images/l_green.png", "./images/l_blue.png", "./images/l_purple.png", "./images/l_grey.png",  \
                           "./images/l_gold.png", "./images/l_silver.png", NULL};


void set_band_color(GtkWidget *band_no_color, guint color, guint file) {
  switch (file) {
    case 0:
      gtk_image_set_from_file(GTK_IMAGE(band_no_color), imageText_l[color]);
      break;
    case 1:
      gtk_image_set_from_file(GTK_IMAGE(band_no_color), imageText_l_2[color]);
      break;
  }
}

void set_visible_band(guint band_count) {
  switch (band_count) {
    case 3:
      gtk_image_clear(GTK_IMAGE(band_4_color));
      gtk_image_clear(GTK_IMAGE(band_5_color));
      gtk_image_clear(GTK_IMAGE(band_6_color));
    case 4:
      gtk_image_clear(GTK_IMAGE(band_5_color));
      gtk_image_clear(GTK_IMAGE(band_6_color));
    case 5:
      gtk_image_clear(GTK_IMAGE(band_6_color));
    case 6:
      break;
  }
}