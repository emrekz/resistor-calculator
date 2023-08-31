#include "header.h"
guint band_count = 3;

const char *bandCount[] = {"Three", "Four", "Five", "Six", NULL};
const char *band1[] = {"Black", "Brown", "Red", "Orange", "Yellow", "Green", "Blue", "Purple", "Grey", "White", NULL};
const char *band2[] = {"Black", "Brown", "Red", "Orange", "Yellow", "Green", "Blue", "Purple", "Grey", "White", NULL};
const char *band3_3[] = {"Black", "Brown", "Red", "Orange", "Yellow", "Green", "Blue", "Purple", "Grey", "White", "Gold", "Silver", NULL};
const char *band3_4[] = {"Black", "Brown", "Red", "Orange", "Yellow", "Green", "Blue", "Purple", "Grey", "White", "Gold", "Silver", NULL};
const char *band3_5[] = {"Black", "Brown", "Red", "Orange", "Yellow", "Green", "Blue", "Purple", "Grey", "White", NULL};
const char *band3_6[] = {"Black", "Brown", "Red", "Orange", "Yellow", "Green", "Blue", "Purple", "Grey", "White", NULL};
const char *band4_4[] = {"Brown", "Red", "Orange", "Yellow", "Green", "Blue", "Purple", "Grey", "Gold", "Silver", NULL};
const char *band4_5[] = {"Black", "Brown", "Red", "Orange", "Yellow", "Green", "Blue", "Purple", "Grey", "White", "Gold", "Silver", NULL};
const char *band4_6[] = {"Black", "Brown", "Red", "Orange", "Yellow", "Green", "Blue", "Purple", "Grey", "White", "Gold", "Silver", NULL};
const char *band5[] = {"Brown", "Red", "Orange", "Yellow", "Green", "Blue", "Purple", "Grey", "Gold", "Silver", NULL};
const char *band6[] = {"Black", "Brown", "Red", "Orange", "Yellow", "Green", "Blue", "Purple", "Grey", NULL};

GtkWidget *grid;
GtkWidget *dropDown_bandCount;
GtkWidget *dropDown_1;
GtkWidget *dropDown_2;
GtkWidget *dropDown_3;
GtkWidget *dropDown_4;
GtkWidget *dropDown_5;
GtkWidget *dropDown_6;
GtkStringList *band_456_string_list;
GtkWidget *res_lab;

GtkWidget *band_1_color;
GtkWidget *band_2_color;
GtkWidget *band_3_color;
GtkWidget *band_4_color;
GtkWidget *band_5_color;
GtkWidget *band_6_color;

GtkWidget *fix;

static void band_count_disable_dropdown(GtkDropDown *dropdown_band) {
  guint sel = gtk_drop_down_get_selected(dropdown_band);
  switch (sel) {
    case 0:
      g_print("Three");
      gtk_widget_set_sensitive(dropDown_4, false);
      gtk_widget_set_sensitive(dropDown_5, false);
      gtk_widget_set_sensitive(dropDown_6, false);
      band_count = 3;
      band_456_string_list = gtk_string_list_new(band3_3);
      gtk_drop_down_set_model(GTK_DROP_DOWN(dropDown_3), G_LIST_MODEL(band_456_string_list));
      set_visible_band(band_count);
      break;
    case 1:
      g_print("Four");
      gtk_widget_set_sensitive(dropDown_4, true);
      gtk_widget_set_sensitive(dropDown_5, false);
      gtk_widget_set_sensitive(dropDown_6, false);
      band_count = 4;
      band_456_string_list = gtk_string_list_new(band3_4);
      gtk_drop_down_set_model(GTK_DROP_DOWN(dropDown_3), G_LIST_MODEL(band_456_string_list));
      band_456_string_list = gtk_string_list_new(band4_4);
      gtk_drop_down_set_model(GTK_DROP_DOWN(dropDown_4), G_LIST_MODEL(band_456_string_list));
      set_visible_band(band_count);
      break;
    case 2:
      g_print("Five");
      gtk_widget_set_sensitive(dropDown_4, true);
      gtk_widget_set_sensitive(dropDown_5, true);
      gtk_widget_set_sensitive(dropDown_6, false);
      band_count = 5;
      band_456_string_list = gtk_string_list_new(band3_5);
      gtk_drop_down_set_model(GTK_DROP_DOWN(dropDown_3), G_LIST_MODEL(band_456_string_list));
      band_456_string_list = gtk_string_list_new(band4_5);
      gtk_drop_down_set_model(GTK_DROP_DOWN(dropDown_4), G_LIST_MODEL(band_456_string_list));
      set_visible_band(band_count);
      break;
    case 3:
      g_print("Six");
      gtk_widget_set_sensitive(dropDown_4, true);
      gtk_widget_set_sensitive(dropDown_5, true);
      gtk_widget_set_sensitive(dropDown_6, true);
      band_count = 6;
      band_456_string_list = gtk_string_list_new(band3_6);
      gtk_drop_down_set_model(GTK_DROP_DOWN(dropDown_3), G_LIST_MODEL(band_456_string_list));
      band_456_string_list = gtk_string_list_new(band4_6);
      gtk_drop_down_set_model(GTK_DROP_DOWN(dropDown_4), G_LIST_MODEL(band_456_string_list));
      set_visible_band(band_count);
      break;
  }
}

static void activate(GtkApplication *app, gpointer user_data) {
  GtkWidget *window;
  GtkWidget *lab, *lab2;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Resistor Calculator v.0.1");
  gtk_window_set_default_size(GTK_WINDOW(window), 600, 350);
  gtk_window_set_resizable(GTK_WINDOW(window), false);
  
  fix = gtk_fixed_new();

  gtk_window_set_child(GTK_WINDOW(window), fix);
  
  grid = gtk_grid_new();
  gtk_grid_set_row_spacing(GTK_GRID(grid), 6);
  gtk_grid_set_column_spacing(GTK_GRID(grid), 6);
  gtk_widget_set_margin_start(grid, 10);
  gtk_widget_set_margin_top(grid, 10);
  gtk_fixed_put(GTK_FIXED(fix), grid, 0, 0);


  lab = gtk_label_new("Band Count : ");
  gtk_grid_attach(GTK_GRID(grid), lab, 0, 0, 1, 1);
  dropDown_bandCount = gtk_drop_down_new_from_strings(bandCount);
  g_signal_connect(dropDown_bandCount, "notify::selected", G_CALLBACK(band_count_disable_dropdown), NULL);
  gtk_grid_attach(GTK_GRID(grid), dropDown_bandCount, 1, 0, 1, 1);

  lab = gtk_label_new("1. Band Color : ");
  gtk_grid_attach(GTK_GRID(grid), lab, 0, 1, 1, 1);
  dropDown_1 = gtk_drop_down_new_from_strings(band1);
  g_signal_connect(dropDown_1, "notify::selected", G_CALLBACK(band_1_calc), NULL);
  gtk_grid_attach(GTK_GRID(grid), dropDown_1, 1, 1, 1, 1);

  lab = gtk_label_new("2. Band Color : ");
  gtk_grid_attach(GTK_GRID(grid), lab, 0, 2, 1, 1);
  dropDown_2 = gtk_drop_down_new_from_strings(band2);
  g_signal_connect(dropDown_2, "notify::selected", G_CALLBACK(band_2_calc), NULL);
  gtk_grid_attach(GTK_GRID(grid), dropDown_2, 1, 2, 1, 1);

  lab = gtk_label_new("3. Band Color : ");
  gtk_grid_attach(GTK_GRID(grid), lab, 0, 3, 1, 1);
  dropDown_3 = gtk_drop_down_new_from_strings(band3_6);
  g_signal_connect(dropDown_3, "notify::selected", G_CALLBACK(band_3_calc), NULL);
  gtk_grid_attach(GTK_GRID(grid), dropDown_3, 1, 3, 1, 1);

  lab = gtk_label_new("4. Band Color : ");
  gtk_grid_attach(GTK_GRID(grid), lab, 0, 4, 1, 1);
  dropDown_4 = gtk_drop_down_new_from_strings(band4_6);
  g_signal_connect(dropDown_4, "notify::selected", G_CALLBACK(band_4_calc), NULL);
  gtk_grid_attach(GTK_GRID(grid), dropDown_4, 1, 4, 1, 1);

  lab = gtk_label_new("5. Band Color : ");
  gtk_grid_attach(GTK_GRID(grid), lab, 0, 5, 1, 1);
  dropDown_5 = gtk_drop_down_new_from_strings(band5);
  g_signal_connect(dropDown_5, "notify::selected", G_CALLBACK(band_5_calc), NULL);
  gtk_grid_attach(GTK_GRID(grid), dropDown_5, 1, 5, 1, 1);

  lab = gtk_label_new("6. Band Color : ");
  gtk_grid_attach(GTK_GRID(grid), lab, 0, 6, 1, 1);
  dropDown_6 = gtk_drop_down_new_from_strings(band6);
  g_signal_connect(dropDown_6, "notify::selected", G_CALLBACK(band_6_calc), NULL);
  gtk_grid_attach(GTK_GRID(grid), dropDown_6, 1, 6, 1, 1);

  res_lab = gtk_label_new("Resistor Value : ");
  gtk_fixed_put(GTK_FIXED(fix), res_lab, 280, 50);

  lab2 = gtk_label_new("Coded by Emre KOZALTI - © 2023");
  gtk_fixed_put(GTK_FIXED(fix), lab2, 450, 290);
  gtk_widget_add_css_class(lab2, "label2");
   
  GtkWidget *image;
  image = gtk_image_new_from_file("./images/base.png");
  gtk_image_set_pixel_size(GTK_IMAGE(image), 299);
  gtk_fixed_put(GTK_FIXED(fix), image, 220, 0);

  band_1_color = gtk_image_new_from_file("./images/l_black.png");
  gtk_image_set_pixel_size(GTK_IMAGE(band_1_color), 60);
  gtk_fixed_put(GTK_FIXED(fix), band_1_color, 265, 119);
  band_2_color = gtk_image_new_from_file("./images/l_black.png");
  gtk_image_set_pixel_size(GTK_IMAGE(band_2_color), 50);
  gtk_fixed_put(GTK_FIXED(fix), band_2_color, 305, 124);
  band_3_color = gtk_image_new_from_file("./images/l_black.png");
  gtk_image_set_pixel_size(GTK_IMAGE(band_3_color), 50);
  gtk_fixed_put(GTK_FIXED(fix), band_3_color, 330, 124);
  band_4_color = gtk_image_new_from_file("./images/l_black.png");
  gtk_image_set_pixel_size(GTK_IMAGE(band_4_color), 50);
  gtk_fixed_put(GTK_FIXED(fix), band_4_color, 355, 124);
  band_5_color = gtk_image_new_from_file("./images/l_brown.png");
  gtk_image_set_pixel_size(GTK_IMAGE(band_5_color), 50);
  gtk_fixed_put(GTK_FIXED(fix), band_5_color, 395, 124);
  band_6_color = gtk_image_new_from_file("./images/l_black.png");
  gtk_image_set_pixel_size(GTK_IMAGE(band_6_color), 60);
  gtk_fixed_put(GTK_FIXED(fix), band_6_color, 425, 119);


  GtkCssProvider * provider;
  provider = gtk_css_provider_new();
  gtk_css_provider_load_from_file(provider, g_file_new_for_path("style.css"));
  gtk_style_context_add_provider_for_display(gtk_widget_get_display(window), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
  gtk_widget_add_css_class(res_lab, "label");

  gtk_widget_set_visible(window, true);
}


int main(int argc, char **argv) {
  GtkApplication *app;
  int status;

  app = gtk_application_new("zart.zurt", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);
  
  return status;
}