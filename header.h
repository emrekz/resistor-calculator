#include <gtk/gtk.h>

extern GtkWidget *res_lab;
extern GtkWidget *fix;

extern GtkWidget *band_1_color;
extern GtkWidget *band_2_color;
extern GtkWidget *band_3_color;
extern GtkWidget *band_4_color;
extern GtkWidget *band_5_color;
extern GtkWidget *band_6_color;

extern guint band_count;

extern gint _3band_calculated;
extern gint _4band_calculated;
extern gint _5band_calculated;
extern gint _6band_calculated;

extern guint _band1_selected;
extern guint _band2_selected;
extern guint _band3_selected;
extern guint _band4_selected;
extern guint _band5_selected;
extern guint _band6_selected;

extern const char *band1[];
extern const char *band2[];
extern const char *band3_3[];
extern const char *band3_4[];
extern const char *band3_5[]; 
extern const char *band3_6[]; 
extern const char *band4_4[]; 
extern const char *band4_5[]; 
extern const char *band4_6[]; 
extern const char *band5[]; 
extern const char *band6[]; 

void band_1_calc(GtkDropDown *dropdown);
void band_2_calc(GtkDropDown *dropdown);
void band_3_calc(GtkDropDown *dropdown);
void band_4_calc(GtkDropDown *dropdown);
void band_5_calc(GtkDropDown *dropdown);
void band_6_calc(GtkDropDown *dropdown);

void _3_band_calc(guint band_1, guint band_2, guint band_3);
void _4_band_calc(guint band_1, guint band_2, guint band_3, guint band_4);
void _5_band_calc(guint band_1, guint band_2, guint band_3, guint band_4, guint band_5);
void _6_band_calc(guint band_1, guint band_2, guint band_3, guint band_4, guint band_5, guint band_6);

void set_band_color(GtkWidget *band_no_color, guint color, guint fileArray);
void set_visible_band(guint band_count);
gchar *check_float_value(double num);