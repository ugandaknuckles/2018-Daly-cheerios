#include<iostream>
#include<allegro5/allegro.h>
#include<allegro5\allegro_primitives.h>
using namespace std;

int main() {
	srand(time(NULL));
	al_init();
	al_init_primitives_addon();
	ALLEGRO_DISPLAY *display = al_create_display(800, 800);

	while (1) {
		al_draw_filled_circle(rand()%800, rand()%800, rand()%200, al_map_rgb(rand()%256, 0,rand()%256));
		al_rest(.02);
		al_flip_display();
	}

	al_destroy_display(display);

}