#pragma once


#include <termios.h>
#include "ofMain.h"

    #include "OMXReader.h"
    #include "OMXPlayerSubtitles.h"

#include "OMXControl.h"
#include "KeyConfig.h"
#include "Keyboard.h"

#include "version.h"

/// static Keyboard    *m_keyboard;
/// static volatile sig_atomic_t g_abort;


class phOmxPlayerUtils {

public:
    volatile sig_atomic_t g_abort;
    /*static*/ void sig_handler(int s);
    void print_usage();
    void print_keybindings();
    void print_version();
    void PrintSubtitleInfo();

///FileUtils
    bool Exists(const std::string& path);
    bool IsURL(const std::string& str);
    bool IsPipe(const std::string& str);
/*
///SubTitle
    bool        m_has_external_subtitles = false;
    std::string m_external_subtitles_path ="";
    bool        m_has_subtitle = false;
    OMXPlayerSubtitles  m_player_subtitles;
*/
    OMXReader   m_omx_reader;
    Keyboard   *m_keyboard;

};

/// Keyboard*         OMXplayer::m_keyboard;
