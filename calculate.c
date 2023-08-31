#include "header.h"
#include <math.h>

gint _3band_calculated = 0;
gint _4band_calculated = 0;
gint _5band_calculated = 0;
gint _6band_calculated = 0;

guint _band1_selected = 0;
guint _band2_selected = 0;
guint _band3_selected = 0;
guint _band4_selected = 0;
guint _band5_selected = 0;
guint _band6_selected = 0;

const char *tolerance[] = {"±1%", "±2%", "±0.05%", "±0.02%", "±0.5%", "±0.25%", "±0.1%", "±0.01%", "±5%", "±10%", NULL};
const char *temp_coff[] = {"250ppm/K", "100ppm/K", "50ppm/K", "15ppm/K", "25ppm/K", "20ppm/K", "10ppm/K", "5ppm/K", "1ppm/K", NULL};
const double multi[] = {1, 10, 100, 1000*1, 1000*10, 1000*100, 1000000*1, 1000000*10, 1000000*100, 1000000000, 0.1, 0.01};

void band_1_calc(GtkDropDown *dropdown) {
  _band1_selected = gtk_drop_down_get_selected(dropdown);
  switch (band_count) {
    case 3:
      _3_band_calc(_band1_selected, _band2_selected, _band3_selected);
      break;
    case 4:
      _4_band_calc(_band1_selected, _band2_selected, _band3_selected, _band4_selected);
      break;
    case 5:
      _5_band_calc(_band1_selected, _band2_selected, _band3_selected, _band4_selected, _band5_selected);
      break;
    case 6:
      _6_band_calc(_band1_selected, _band2_selected, _band3_selected, _band4_selected, _band5_selected, _band6_selected);
      break;
  }
  set_band_color(band_1_color, _band1_selected, 0);
}
void band_2_calc(GtkDropDown *dropdown) {
  _band2_selected = gtk_drop_down_get_selected(dropdown);
  switch (band_count) {
    case 3:
      _3_band_calc(_band1_selected, _band2_selected, _band3_selected);
      break;
    case 4:
      _4_band_calc(_band1_selected, _band2_selected, _band3_selected, _band4_selected);
      break;
    case 5:
      _5_band_calc(_band1_selected, _band2_selected, _band3_selected, _band4_selected, _band5_selected);
      break;
    case 6:
      _6_band_calc(_band1_selected, _band2_selected, _band3_selected, _band4_selected, _band5_selected, _band6_selected);
      break;
  }
  set_band_color(band_2_color, _band2_selected, 0);
}
void band_3_calc(GtkDropDown *dropdown) {
  _band3_selected = gtk_drop_down_get_selected(dropdown);
  switch (band_count) {
    case 3:
      _3_band_calc(_band1_selected, _band2_selected, _band3_selected);
      break;
    case 4:
      _4_band_calc(_band1_selected, _band2_selected, _band3_selected, _band4_selected);
      break;
    case 5:
      _5_band_calc(_band1_selected, _band2_selected, _band3_selected, _band4_selected, _band5_selected);
      break;
    case 6:
      _6_band_calc(_band1_selected, _band2_selected, _band3_selected, _band4_selected, _band5_selected, _band6_selected);
      break;
  }
  set_band_color(band_3_color, _band3_selected, 0);
}

void band_4_calc(GtkDropDown *dropdown) {
  _band4_selected = gtk_drop_down_get_selected(dropdown);
  switch (band_count) {
    case 4:
      _4_band_calc(_band1_selected, _band2_selected, _band3_selected, _band4_selected);
      set_band_color(band_4_color, _band4_selected, 1);
      break;
    case 5:
      _5_band_calc(_band1_selected, _band2_selected, _band3_selected, _band4_selected, _band5_selected);
      set_band_color(band_4_color, _band4_selected, 0);
      break;
    case 6:
      _6_band_calc(_band1_selected, _band2_selected, _band3_selected, _band4_selected, _band5_selected, _band6_selected);
      set_band_color(band_4_color, _band4_selected, 0);
      break;
  }
}

void band_5_calc(GtkDropDown *dropdown) {
  _band5_selected = gtk_drop_down_get_selected(dropdown);
  switch (band_count) {
    case 5:
      _5_band_calc(_band1_selected, _band2_selected, _band3_selected, _band4_selected, _band5_selected);
      break;
    case 6:
      _6_band_calc(_band1_selected, _band2_selected, _band3_selected, _band4_selected, _band5_selected, _band6_selected);
      break;
  }
  set_band_color(band_5_color, _band5_selected, 1);
}

void band_6_calc(GtkDropDown *dropdown) {
  _band6_selected = gtk_drop_down_get_selected(dropdown);
  switch (band_count) {
    case 6:
      _6_band_calc(_band1_selected, _band2_selected, _band3_selected, _band4_selected, _band5_selected, _band6_selected);
      break;
  }
  set_band_color(band_6_color, _band6_selected, 0);
}

gchar res_str[50] = {0};
gdouble num = 0;
void _3_band_calc(guint band_1, guint band_2, guint band_3) {
  num = (gdouble)band_1*10 + (gdouble)band_2*1;
  num *= (gdouble)multi[band_3];
  strcpy(res_str, check_float_value(num));
  strcat(res_str, " Ω  ±20%");
  gtk_label_set_label(GTK_LABEL(res_lab), res_str);
}

void _4_band_calc(guint band_1, guint band_2, guint band_3, guint band_4) {
  num = (gdouble)band_1*10 + (gdouble)band_2*1;
  num *= (gdouble)multi[band_3];
  strcpy(res_str, check_float_value(num));
  strcat(res_str, " Ω  ");
  strcat(res_str, tolerance[band_4]);
  gtk_label_set_label(GTK_LABEL(res_lab), res_str);
}

void _5_band_calc(guint band_1, guint band_2, guint band_3, guint band_4, guint band_5) {
  num = (gdouble)band_1*100 + (gdouble)band_2*10 + (gdouble)band_3*1;
  num *= (gdouble)multi[band_4];
  strcpy(res_str, check_float_value(num));
  strcat(res_str, " Ω  ");
  strcat(res_str, tolerance[band_5]);
  gtk_label_set_label(GTK_LABEL(res_lab), res_str);
}

void _6_band_calc(guint band_1, guint band_2, guint band_3, guint band_4, guint band_5, guint band_6) {
  num = (gdouble)band_1*100 + (gdouble)band_2*10 + (gdouble)band_3*1;
  num *= (gdouble)multi[band_4];
  strcpy(res_str, check_float_value(num));
  strcat(res_str, " Ω  ");
  strcat(res_str, tolerance[band_5]);
  strcat(res_str, "  ");
  strcat(res_str, temp_coff[band_6]);
  gtk_label_set_label(GTK_LABEL(res_lab), res_str);
}

gchar check_value[50] = {0};
gchar *check_float_value(double num) {
  float div_K = num / 1000;
  float div_M = num / 1000000;
  float div_G = num / 1000000000;
  double rem_K = fmod(num, 1000);
  double rem_M = fmod(num, 1000000);
  double rem_G = fmod(num, 1000000000);
  
  if(div_K >= 1) {
    if(rem_K!=0) {
      printf("hey");
      sprintf(check_value, "%.2f", div_K);
    } else {
      sprintf(check_value, "%.0f", div_K);
    }
    strcat(check_value, "K ");
    if(div_M >= 1) {
      if(rem_M!=0) {
        sprintf(check_value, "%.2f", div_M);
      } else {
        sprintf(check_value, "%.0f", div_M);
      }
      strcat(check_value, "M ");
      if(div_G >= 1) {
        if(rem_G!=0) {
          sprintf(check_value, "%.2f", div_G);
        } else {
          sprintf(check_value, "%.0f", div_G);
        }
        strcat(check_value, "G ");
      }
    }
  } else {
    sprintf(check_value, "%.2f", num);
  }
  return check_value;
}