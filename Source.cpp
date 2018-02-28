#include<iostream>
#include<allegro5/allegro.h>
#include<allegro5\allegro_primitives.h>
using namespace std;

int main() {

	srand(time(NULL));
	al_init();
	al_init_primitives_addon();
	ALLEGRO_DISPLAY *display = al_create_display(800, 800);

	cout << "modern art" << endl;
	
	al_draw_filled_triangle(400, 600, 600, 400, 600, 100, al_map_rgb(400, 0, 200));
	al_draw_filled_circle(400, 300, 60, al_map_rgb(255, 255, 255));
	al_draw_filled_circle(700, 300, 60, al_map_rgb(255, 255, 255));
	al_draw_line(750, 100, 400, 100, al_map_rgb(255, 255, 255), 5);
	al_draw_filled_ellipse(460, 700, 200, 100, al_map_rgb(600, 40, 40));

	al_flip_display();
	al_rest(10);
	al_destroy_display(display);

	system("pause");
}