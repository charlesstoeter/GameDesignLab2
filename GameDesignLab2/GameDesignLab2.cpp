#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>




int main()
{
	// Initialize Allegro
	if (!al_init()) {
		std::cerr << "Failed to initialize Allegro!" << std::endl;
		return -1;
	}
	// Initialize Allegro Font and TTF
	if (!al_init_font_addon() || !al_init_ttf_addon()) {
		std::cerr << "Failed to initialize font addons!" << std::endl;
		return -1;
	}
	// Initialize Allegro Primitives
	if (!al_init_primitives_addon()) {
		std::cerr << "Failed to initialize primitives addon!" << std::endl;
		return -1;
	}



	// Initialize Allegro Keyboard
	if (!al_install_keyboard()) {
		std::cerr << "Failed to initialize keyboard!" << std::endl;
		return -1;
	}

	// Create a display
	ALLEGRO_DISPLAY* display = al_create_display(800, 600);
	if (!display) {
		std::cerr << "Failed to create display!" << std::endl;
		return -1;
	}

	al_clear_to_color(al_map_rgb(0, 0, 0)); // Clear the display with black color

	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0); // 60 FPS
	bool running = true;

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_start_timer(timer);

	float x = 400, y = 300; // Initial position of the circle
	float step = 10; // Step size for movement
	while (running) {
		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);

		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			running = false;
		}
		else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (event.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				y -= step;
				break;

			case ALLEGRO_KEY_DOWN:
				y += step;
				break;

			case ALLEGRO_KEY_LEFT:
				x -= step;
				break;

			case ALLEGRO_KEY_RIGHT:
				x += step;
				break;

			case ALLEGRO_KEY_U:
				x -= step;
				y -= step;
				break;

			case ALLEGRO_KEY_D:
				x += step;
				y += step;
				break;

			case ALLEGRO_KEY_R:
				x += step;
				y -= step;
				break;

			case ALLEGRO_KEY_L:
				x -= step;
				y += step;
				break;

			case ALLEGRO_KEY_ESCAPE: // optional: exit program
				running = false;
				break;
			}

		}
		else if (event.type == ALLEGRO_EVENT_TIMER) {
			al_clear_to_color(al_map_rgb(0, 0, 0)); // Clear the display with black color
			int half_size = 25; 
			al_draw_filled_rectangle(x - half_size, y - half_size, x + half_size, y + half_size, al_map_rgb(255, 0, 0));
			al_flip_display(); //Flips the Display
		}
	}

	// Cleanup
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	return 0;
	
}
	
