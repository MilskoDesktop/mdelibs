#include <MDE/Audio/Audio.h>

#ifdef USE_MA
#include <miniaudio.c>

typedef struct driver {
	MDEAudioHandler handler;
	void*		user;
	ma_device device;
} driver_t;

void data_callback(ma_device* device, void* output, const void* input, ma_uint32 frame_count){
	driver_t* drv = device->pUserData;

	drv->handler(drv, drv->user, output, frame_count);
}

MDEAudio MDEAudioOpen(MDEAudioHandler handler, void* user){
	driver_t* drv = malloc(sizeof(*drv));
	ma_device_config config = ma_device_config_init(ma_device_type_playback);
	config.playback.format = ma_format_s16;
	config.playback.channels = 2;
	config.sampleRate = MDEAudioRate;
	config.dataCallback = data_callback;
	config.pUserData = drv;

	drv->handler = handler;
	drv->user = user;

	if(ma_device_init(NULL, &config, &drv->device) != MA_SUCCESS){
		free(drv);
		return NULL;
	}

	return drv;
}

void MDEAudioClose(MDEAudio handle){
	driver_t* drv = handle;
	ma_device_uninit(&drv->device);
	free(handle);
}

void MDEAudioStart(MDEAudio handle){
	driver_t* drv = handle;
	ma_device_start(&drv->device);
}
#endif
