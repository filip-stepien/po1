#include "sounds.h"

#include <iostream>

Sounds::Sounds() {
	al_reserve_samples(64);

	this->music = al_create_sample_instance(al_load_sample("music.wav"));
	this->option = al_create_sample_instance(al_load_sample("option.wav"));
	this->bounce_idx = 0;
	this->powerup_idx = 0;
	this->shot_idx = 0;

	for (int i = 0; i < 10; i++) {
		this->bounces.push_back(al_create_sample_instance(al_load_sample("bounce.wav")));
		al_attach_sample_instance_to_mixer(this->bounces[i], al_get_default_mixer());
		al_set_sample_instance_gain(this->bounces[i], config.volume);

		this->powerups.push_back(al_create_sample_instance(al_load_sample("powerup.wav")));
		al_attach_sample_instance_to_mixer(this->powerups[i], al_get_default_mixer());
		al_set_sample_instance_gain(this->powerups[i], config.volume);

		this->shots.push_back(al_create_sample_instance(al_load_sample("shot.wav")));
		al_attach_sample_instance_to_mixer(this->shots[i], al_get_default_mixer());
		al_set_sample_instance_gain(this->shots[i], config.volume);
	}

	al_attach_sample_instance_to_mixer(music, al_get_default_mixer());;
	al_attach_sample_instance_to_mixer(option, al_get_default_mixer());

	al_set_sample_instance_gain(music, config.volume);
	al_set_sample_instance_gain(option, config.volume);

	al_set_sample_instance_playmode(music, ALLEGRO_PLAYMODE_LOOP);
}

void Sounds::play_music() {
	al_play_sample_instance(music);
}

void Sounds::play_bounce() {
	al_play_sample_instance(bounces[bounce_idx]);
	bounce_idx == 9 ? bounce_idx = 0 : bounce_idx++;
}

void Sounds::play_shot() {
	al_play_sample_instance(shots[shot_idx]);
	shot_idx == 9 ? shot_idx = 0 : shot_idx++;
}

void Sounds::play_powerup() {
	al_play_sample_instance(powerups[powerup_idx]);
	powerup_idx == 9 ? powerup_idx = 0 : powerup_idx++;
}

void Sounds::play_option() {
	al_play_sample_instance(option);
}

void Sounds::mute() {
	for (int i = 0; i < 10; i++) {
		al_set_sample_instance_gain(bounces[i], 0.0f);
		al_set_sample_instance_gain(shots[i], 0.0f);
		al_set_sample_instance_gain(powerups[i], 0.0f);
	}

	al_set_sample_instance_gain(music, 0.0f);
	al_set_sample_instance_gain(option, 0.0f);
}

void Sounds::unmute() {
	for (int i = 0; i < 10; i++) {
		al_set_sample_instance_gain(bounces[i], config.volume);
		al_set_sample_instance_gain(shots[i], config.volume);
		al_set_sample_instance_gain(powerups[i], config.volume);
	}

	al_set_sample_instance_gain(music, config.volume);
	al_set_sample_instance_gain(option, config.volume);
}