#pragma once

#include "ofMain.h"

#include "rpiUtils.h"
#include "phomxPlayerUtis.h"

class phOMXplayer {

public:

    int omxPlayerCli (char* str);
    int omxplayerOrig( int argc, char** argv);
    int do_exit();

private:

    RPIutils* rpiUtils;
    phOmxPlayerUtils* pUtils;

    void SetVideoMode(int width, int height, int fpsrate, int fpsscale, FORMAT_3D_T is3d);
/*
    void SetSpeed(int iSpeed);
    void FlushStreams(double pts);
*/

};
