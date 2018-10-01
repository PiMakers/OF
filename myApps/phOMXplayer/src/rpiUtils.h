#pragma once

#include "ofConstants.h"

#include "OMXClock.h"
#include "OMXReader.h"

typedef enum {CONF_FLAGS_FORMAT_NONE, CONF_FLAGS_FORMAT_SBS, CONF_FLAGS_FORMAT_TB, CONF_FLAGS_FORMAT_FP } FORMAT_3D_T;

class RPIutils {

public:
///    bool    m_gen_log;
///    bool    m_NativeDeinterlace;

/*static*/ int get_mem_gpu(void);
/*static*/ float get_display_aspect_ratio(HDMI_ASPECT_T aspect);
/*static*/ float get_display_aspect_ratio(SDTV_ASPECT_T aspect);
static void CallbackTvServiceCallback(void *userdata, uint32_t reason, uint32_t param1, uint32_t param2);
///    void SetVideoMode(int width, int height, int fpsrate, int fpsscale, FORMAT_3D_T is3d);

};
