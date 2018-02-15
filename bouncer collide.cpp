#include <allegro5/allegro.h>
#include <allegro5\allegro_primitives.h>
#include <stdio.h>
#include<iostream>
using namespace std;

const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int BOUNCER_SIZE = 32;
const int BOUNCER2_SIZE = 32;

bool PixelCollide(int xl, int yl, int x2, int y2);

enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT


};

enum MYKEYS2 {
	KEY_W, KEY_S, KEY_A, KEY_D


};

int main() {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_BITMAP *bouncer2 = NULL;
	float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;

	float bouncer2_x = 10;
	float bouncer2_y = 50;
	bool key1[4] = { false, false, false, false };//remember to change the key number for multiple people to play
	bool key2[4] = { false, false, false, false };
	bool redraw = true;
	bool doexit = false;

	al_init();
	al_install_keyboard();
	timer = al_create_timer(1.0 / FPS);

	display = al_create_display(SCREEN_W, SCREEN_H);

	bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);
	bouncer2 = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);
	
	al_set_target_bitmap(bouncer);
	al_clear_to_color(al_map_rgb(255, 0, 255));

	al_set_target_bitmap(bouncer2);

	al_clear_to_color(al_map_rgb(255, 50, 255));
	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	 
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	while (!doexit)

	{

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (key1[KEY_UP] && bouncer_y >= 4.0) {
				bouncer_y -= 1.0;
			}

			if (key1[KEY_DOWN] && bouncer_y <= SCREEN_H - BOUNCER_SIZE - 2.0) {
				bouncer_y += 1.0;
			}

			if (key1[KEY_LEFT] && bouncer_x >= 4.0) {
				bouncer_x -= 1.0;
			}

			if (key1[KEY_RIGHT] && bouncer_x <= SCREEN_W - BOUNCER_SIZE - 2.0) {
				bouncer_x += 1.0;
			}
			if (PixelCollide( bouncer_x, bouncer_y, bouncer2_x, bouncer2_y) == true) {
				cout << "collide!";
			}
			if (key2[KEY_W] && bouncer2_y >= 4.0) {
				bouncer2_y -= 1.0;
			}

			if (key2[KEY_S] && bouncer2_y <= SCREEN_H - BOUNCER_SIZE - 4.0) {
				bouncer2_y += 1.0;
			}

			if (key2[KEY_A] && bouncer2_x >= 4.0) {
				bouncer2_x -= 1.0;
			}

			if (key2[KEY_D] && bouncer2_x <= SCREEN_W - BOUNCER_SIZE - 4.0) {
				bouncer2_x += 1.0;
			}

			
			redraw = true;
		}
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key1[KEY_UP] = true;
				break;

			case ALLEGRO_KEY_DOWN:
				key1[KEY_DOWN] = true;
				break;

			case ALLEGRO_KEY_LEFT:
				key1[KEY_LEFT] = true;
				break;

			case ALLEGRO_KEY_RIGHT:
				key1[KEY_RIGHT] = true;
				break;

			case ALLEGRO_KEY_W:
				key2[KEY_W] = true;
				break;

			case ALLEGRO_KEY_S:
				key2[KEY_S] = true;
				break;

			case ALLEGRO_KEY_A:
				key2[KEY_A] = true;
				break;

			case ALLEGRO_KEY_D:
				key2[KEY_D] = true;
				break;
			}
		}

	
	
	
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_W:
				key2[KEY_W] = false;
				break;

			case ALLEGRO_KEY_S:
				key2[KEY_S] = false;
				break;

			case ALLEGRO_KEY_A:
				key2[KEY_A] = false;
				break;

			case ALLEGRO_KEY_D:
				key2[KEY_D] = false;
				break;

			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;

			case ALLEGRO_KEY_UP:
				key1[KEY_UP] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key1[KEY_DOWN] = false;
				break;

			case ALLEGRO_KEY_LEFT:
				key1[KEY_LEFT] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key1[KEY_RIGHT] = false;
				break;

				//add key ups for bouncer 1
			}
		}
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);
			al_draw_bitmap(bouncer2, bouncer2_x, bouncer2_y, 0);

			al_flip_display();
		}
	}

	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);


	return 0;
}
bool PixelCollide(int x1, int y1, int x2, int y2) {
	if (x1 == x2 && y1 == y2)
		return true;
	else
		return false;
 }
