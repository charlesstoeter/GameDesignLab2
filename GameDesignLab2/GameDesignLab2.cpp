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

	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();


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

	while (true) {
		// Draw a red rectangle
		al_draw_filled_rectangle(100, 100, 300, 300, al_map_rgb(255, 0, 0));
		// Draw a blue circle
		al_draw_filled_circle(400, 300, 50, al_map_rgb(0, 0, 255));
		// Draw some text
		ALLEGRO_FONT* font = al_load_ttf_font("arial.ttf", 36, 0);
		if (font) {
			al_draw_text(font, al_map_rgb(255, 255, 255), 400, 500, ALLEGRO_ALIGN_CENTER, "Hello Allegro!");
			al_destroy_font(font);
		}

		al_flip_display(); // Update the display
		al_rest(1.0); // Pause for a second
	}

	
	
}
