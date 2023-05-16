#include <allegro.h>
#include <cstdio>
class BUTTON
{
      private:
              int x,y,v;
              BITMAP* button;
      public:
             BUTTON(int coor_x, int coor_y, int width, int height, int color, BITMAP* background, int value) : button(NULL), v(value)
             {
                 x = coor_x;
                 y = coor_y;

                 button = create_bitmap(width,height);
                 if (background == NULL)
                    clear_to_color(button, color);
                 else
                     button = background;
             }
             void delete_button() {destroy_bitmap(button);} 
             void show(BITMAP* bitmap) {blit(button,bitmap,0,0,x,y,button->w,button->h);} 
             bool mouseover()
             {
                  if (x <= mouse_x and mouse_x <= x+button->w and y <= mouse_y and mouse_y <= y+button->h) return true;
                  return false;
             }
             int value() {return v;}
             int coor_x() {return x;}
             int coor_y() {return y;}
             void change_coor(int new_x, int new_y)
             {
                  x = new_x;
                  y = new_y;
             }
};
BUTTON* pole[9];
void init();
void deinit();
bool near9(BUTTON* a, BUTTON* b)
{
     int x1 = a->coor_x(), y1 = a->coor_y(), x2 = b->coor_x(), y2 = b->coor_y();
     if (((x1+100 == x2 xor x1-100 == x2) && y1 == y2) xor ((y1 - 100 == y2 xor  y1+100  == y2) && x1 == x2)) return true;
     return false;
}
void change_coor(BUTTON* a, BUTTON* b)
{
     int temp_x = a->coor_x();
     int temp_y = a->coor_y();
     a->change_coor(b->coor_x(),b->coor_y());
     b->change_coor(temp_x,temp_y);
}
void change(BUTTON* a, BUTTON* b)
{
     if (a->value() != 9)
     {
         change_coor(a,b);
         BUTTON* temp = b;
         b = a;
         a = temp;
     }
}
int main()
{
    init();
    srand(time(NULL));
    
    DATAFILE *data = load_datafile("GAME.dat");
    if (!data)
    {
        set_gfx_mode(GFX_TEXT,0,0,0,0);
        allegro_message("Nie mogê za³adowaæ bazy z grafik¹!");
        allegro_exit();
        return 0;
    }
	int i, j, x = 0, y = 0;
	BITMAP* bufor = create_bitmap(300,300);
    for (i = 0; i < 9; i++)
    {
        pole[i] = new BUTTON(x,y,100,100,makecol(0,0,0),(BITMAP*) data[i].dat,i+1);
        if (x != 200)
        {
              x += 100;              
        }
        else
        {
            y += 100;
            x = 0;
        }
    }
    i = 0;
    while (i < 30)
    {
        x = rand()%9;
        y = rand()%9;
        if (x != y) change(pole[x],pole[y]);
        i++;
    }
    while (!key[KEY_ESC])
    {                         
        for (i = 0; i < 9; i++) if (pole[i]->value() == 9) break;
        for (j = 0; j < 9; j++) if (pole[j]->mouseover() and mouse_b == 1 and near9(pole[j],pole[i])) change(pole[j],pole[i]); 
        for (i = 0; i < 9; i++) pole[i]->show(bufor);
        blit(bufor,screen,0,0,0,0,300,300);
    }

    for (i = 0; i < 9; i++) pole[i]->delete_button();
	destroy_bitmap(bufor);
	unload_datafile(data);
	for (i = 0; i < 9; i++) delete pole[i];
    deinit();
	return 0;
}


void init()
{
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 300, 300, 0, 0);
	if (res != 0)
    {
		allegro_message(allegro_error);
		exit(-1);
	}
	install_keyboard();
	install_mouse();
    show_mouse(screen);
    unscare_mouse(); 
}

void deinit()
{
	clear_keybuf();
	allegro_exit();
}
